#include <array>
#include <boost/asio/ip/tcp.hpp>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/algorithm/string.hpp>
#include <mutex>
#include <fstream>

#include "utils.h"
#include "producer.h"
#include "dns.h"

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

producer::producer(string ip, unsigned short port) {
    this->port = port;
    this->ip = ip;
}

bool find_file(string file) {
    ifstream infile(file);
    return infile.good();
}

vector<char> readfilebytes(const string &name)
{
    ifstream fl(name);
    fl.seekg( 0, ios::end );
    size_t len = (size_t) fl.tellg();
    vector<char> ret(len);
    fl.seekg(0, ios::beg);
    if (len)
        fl.read(&ret[0], len);
    fl.close();
    return std::move(ret);
}

void process_request_producer(tcp::socket *socket_ptr) {
    auto& socket = *socket_ptr;

	char len[4];
    len[3] = len[2] = 0;
    size_t bytes_read = read(socket, buffer(len, 2), transfer_all());
    if (bytes_read < 2)
        return;

    int lenstr = toint(len);
    cout << lenstr << endl;
    char str[lenstr];
    size_t lenfile = read(socket, buffer(str, (size_t) lenstr), transfer_all());
    cout << lenfile << endl;

    string file = string(str, (unsigned long) lenstr);
    cout << file << endl;
    if (lenfile < lenstr || !find_file(file)) {
        char res[4];
        tobytes(-1, res);
        write(socket, buffer(res, 4));
        return;
    }
    system::error_code ec;
    auto bytes = std::move(readfilebytes(file));
    cout << "hello" << endl;
    char b[4];
    tobytes((int) bytes.size(), b);
    write(socket, buffer(b, 4), transfer_all());
    write(socket, buffer(bytes), ec);
    delete socket_ptr;
}

void producer::start(string name) {
    io_service io_service2;
    thread_group threads;
    tcp::acceptor acceptor(io_service2);
    tcp::endpoint endpoint(tcp::v4(), this->port);
    acceptor.open(endpoint.protocol());
    acceptor.set_option(tcp::acceptor::reuse_address(true));
    acceptor.bind(endpoint);
    acceptor.listen();
    dns* dns_service2 = new dns(name, 2, ip, port);
    dns_service2->get_nodes();
    for (int i = 0; i < 100; i++) {
        tcp::socket* socket = new tcp::socket((io_service2));
        acceptor.accept(*socket);
        threads.create_thread([socket]() { process_request_producer(socket); });
    }
}
