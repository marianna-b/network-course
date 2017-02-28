#ifndef NETS_DNS_H
#define NETS_DNS_H

#include <vector>
#include <string>
#include <mutex>
#include <boost/asio/basic_datagram_socket.hpp>
#include <boost/asio/ip/udp.hpp>
#include <boost/array.hpp>
#include "dns_entry.h"

class dns {
public:
    dns(std::string name, bool is_prod, unsigned short port):name(name),is_prod(is_prod), port(port){};
    std::vector<dns_entry> get_nodes();

private:
    void send_request();
    void send_response(unsigned int, boost::asio::ip::udp::endpoint&, boost::asio::ip::udp::endpoint&);

    std::string name;
    bool is_prod;
    std::vector<dns_entry> current;
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
