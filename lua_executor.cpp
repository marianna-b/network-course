#include "lua_executor.h"
#include "dns.h"
#include "utils.h"
#include <boost/asio/ip/tcp.hpp>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/algorithm/string.hpp>
#include <mutex>
#include <fstream>

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

boost::asio::io_service io_service3;
boost::thread_group executor_threads;
std::mutex mtx2;

string execute_lua_code(string code) {
    sleep(20);
    return "Some amazing reslult";
}


void lua_executor::finish_thread(dns* dns_service) {
    {
        std::lock_guard<std::mutex> lock(mtx2);
        used_threads--;
        dns_service->set_thread_count(threads - used_threads);

   }
}

void lua_executor::start_thread(dns* dns_service) {
    {
        std::lock_guard<std::mutex> lock(mtx2);
        used_threads++;
        dns_service->set_thread_count(threads - used_threads);
   }
}

void lua_executor::process_request_executor(dns* dns_service, tcp::socket *socket_ptr) {
    cout << "Received execution task" << endl;
    auto& socket = *socket_ptr;

    char len[4];
    size_t bytes_read = read(socket, buffer(len, 4), transfer_all());
    if (bytes_read < 4)
        return;

    int lenstr = toint(len);
    cout << lenstr << endl;
    char str[lenstr];
    size_t lenfile = read(socket, buffer(str, (size_t) lenstr), transfer_all());
    string lua_code = string(str, lenfile);
    cout << lua_code << endl;

    start_thread(dns_service);
    executor_threads.create_thread([this, dns_service, lua_code, socket_ptr]() {
        string result = execute_lua_code(lua_code);
        cout << result << endl;

        char b[4];
        tobytessig((int) result.size(), b);
        write(*socket_ptr, buffer(b, 4), transfer_all());
        write(*socket_ptr, buffer(result, result.size()), transfer_all());
        this->finish_thread(dns_service);
        sleep(10);
        delete socket_ptr;
    });
}

void lua_executor::start(std::string name) {

    tcp::acceptor acceptor(io_service3);
    tcp::endpoint endpoint(tcp::v4(), this->port);
    acceptor.open(endpoint.protocol());
    acceptor.set_option(tcp::acceptor::reuse_address(true));
    acceptor.bind(endpoint);
    acceptor.listen();

    dns *dns_service = new dns(name, 3, this->ip, this->port, this->threads);
    dns_service->get_nodes();

    for (int i = 0; i < 100; i++) {
        tcp::socket *socket = new tcp::socket((io_service3));
        acceptor.accept(*socket);
        executor_threads.create_thread([this, dns_service, socket]() {
            process_request_executor(dns_service, socket);
        });
    }
}


