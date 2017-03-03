#ifndef NETS_EXECUTOR_H
#define NETS_EXECUTOR_H

#include <string>
#include <boost/asio/basic_stream_socket.hpp>
#include <boost/asio/ip/tcp.hpp>
#include "dns.h"

class lua_executor {

public:
    lua_executor(std::string ip, unsigned short port, unsigned char threads):ip(ip), port(port), threads(threads), used_threads(0) {}
    void start(std::string);

private:
    unsigned short port;
    std::string ip;
    unsigned char threads;
    unsigned char used_threads;

    void process_request_executor(dns *,
        boost::asio::basic_stream_socket <boost::asio::ip::tcp, boost::asio::stream_socket_service<boost::asio::ip::tcp>> *);

    void start_thread(dns *dns_service);

    void finish_thread(dns *dns_service);
};


#endif //NETS_EXECUTOR_H
