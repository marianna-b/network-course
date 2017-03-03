#include <boost/asio/ip/tcp.hpp>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/algorithm/string.hpp>
#include <mutex>
#include <fstream>

#include "consumer.h"
#include "dns.h"
#include "utils.h"

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

thread_group threads;
std::mutex mtx;
io_service io_service1;
string result;

consumer::consumer(string ip, unsigned short port) {
    this->ip = ip;
    this->port = port;
}

void save_file(dns_entry entry, string file) {
    cout << entry.name << " " << entry.ip << " " << entry.port << endl;
    tcp::socket socket(io_service1);
    socket.connect(tcp::endpoint(address::from_string(entry.ip), entry.port));
    char len[4];
    tobytes((int) file.size(), len);
    write(socket, buffer(len, 2), transfer_all());
    write(socket, buffer(file, file.size()), transfer_all());
    size_t bytes_read = read(socket, buffer(len, 4), transfer_all());
    if (bytes_read < 4)
        return;
    int strlen = toint(len);
    cout << strlen << endl;
    if (strlen == -1)
        return;

    char buf[strlen];
    size_t bytes_file = read(socket, buffer(buf, (size_t) strlen), transfer_all());
    if (bytes_file < strlen)
        return;

    cout << "HELLO" << endl;
    ofstream stream;
    stream.open(file+"_"+entry.name);
    if(!stream)
        return;
    stream << buf << endl;
    if(!stream)
        return;
}

void process_request_consumer(dns* dns_service, tcp::socket *socket_ptr) {
    cout << "Received client" << endl;
    auto& socket = *socket_ptr;
    boost::asio::streambuf data;
    read_until(socket, data, '\n');
    istream is(&data);
    string file;
    getline(is, file);

    cout << file << endl;
    vector<dns_entry> list;
    {
        dns_service->get_nodes();
        sleep(3);
        std::lock_guard<std::mutex> lock(mtx);
        list = dns_service->current;
    }
    cout << "Producers: " << list.size() << endl;
    thread_group senders;
    for (int i = 0; i < list.size(); i++) {

        if (list[i].flag == 2) {
            dns_entry e = list[i];
            senders.create_thread([e, file]() { save_file(e, file); });
        }
    }
    senders.join_all();
    result = "done";
    write(socket, buffer(result, result.size()), transfer_all());
    delete socket_ptr;
}

void consumer::start(std::string name) {
    tcp::acceptor acceptor(io_service1);
    tcp::endpoint endpoint(tcp::v4(), this->port);
    acceptor.open(endpoint.protocol());
    acceptor.set_option(tcp::acceptor::reuse_address(true));
    acceptor.bind(endpoint);
    acceptor.listen();

    dns* dns_service = new dns(name, 1, ip, port);
    dns_service->get_nodes();

    for (int i = 0; i < 100; i++) {
        tcp::socket* socket = new tcp::socket((io_service1));
        acceptor.accept(*socket);
        threads.create_thread([dns_service, socket]() { process_request_consumer(dns_service, socket); });
    }
}

