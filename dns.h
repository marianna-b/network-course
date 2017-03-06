#ifndef NETS_DNS_H
#define NETS_DNS_H

#include <vector>
#include <string>
#include <mutex>
#include <boost/asio/basic_datagram_socket.hpp>
#include <boost/asio/ip/udp.hpp>
#include <boost/array.hpp>
#include "dns_entry.h"


int now_mils();

class dns {
public:
    dns(std::string name, char flag, std::string ip, unsigned short port, unsigned char t):name(name), flag(flag), ip(ip), port(port), thread_count(t){};
    void get_nodes();
    std::vector<dns_entry> current;
    void send_request();
    void set_thread_count(unsigned char);

private:
    void send_response(unsigned int, boost::asio::ip::udp::endpoint&, boost::asio::ip::udp::endpoint&);

    std::string name;
    std::string ip;
    char flag;
    unsigned char thread_count;
    int last_request = -1;
    std::mutex mtx;
    unsigned short port;
    int curr_seq_num;

    void listen_dns();
    void process_response(boost::asio::ip::udp::socket*, int);

    void process_request(boost::array<char, 1440> buf, boost::asio::ip::udp::endpoint endpoint,
                             boost::asio::ip::udp::endpoint basic_endpoint);
};


#endif //NETS_DNS_H
