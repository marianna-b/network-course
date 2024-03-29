#include <sys/socket.h>
#include <strings.h>
#include <netinet/in.h>
#include "dns.h"
#include "utils.h"
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <chrono>
#include <boost/asio/ip/tcp.hpp>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/algorithm/string.hpp>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace std::chrono;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::asio::ip;

string group_ip = "239.1.2.3";
unsigned short group_port = 21845;
int timeout_mill = 10000;
thread_group dns_threads;
io_service io_service2;

void dns::listen_dns() {
    udp::socket socket(io_service2);
    udp::endpoint listen_endpoint(address::from_string("0.0.0.0"), group_port);

    socket.open(listen_endpoint.protocol());
    socket.set_option(udp::socket::reuse_address(true));
    socket.bind(listen_endpoint);

    socket.set_option(multicast::join_group(address::from_string(group_ip)));

    for (int i = 1; i < 1000; i++) {
        boost::array<char, 1440> buf;
        udp::endpoint sender_endpoint;

        auto len = socket.receive_from(buffer(buf), sender_endpoint);
        cout << "Received datagram " << len << " " << sender_endpoint.address().to_string() << " " << sender_endpoint.port() << endl;
        if (buf[0] == 0) {
            udp::endpoint local_endpoint = socket.local_endpoint();
            dns_threads.create_thread([this, buf, sender_endpoint, local_endpoint]()
                                      { this->process_request(buf, sender_endpoint, local_endpoint); });
        } else {
            cout << "request should be here" << endl;
        }
    }
}

void dns::send_response(unsigned int seqnum, udp::endpoint& sender_endpoint, udp::endpoint& local_endpoint) {
    cout << "Send response to " << " " << sender_endpoint.address().to_string() << " " << sender_endpoint.port() << endl;

    udp::socket socket(io_service2, local_endpoint.protocol());
    int len = 6;
    vector<dns_entry> tmp;
    {
        std::lock_guard<std::mutex> lock(mtx);
        tmp.push_back(dns_entry(this->ip, this->port, this->flag, this->name, this->thread_count));
    }
    int j = 0;
    for (j; j < tmp.size() && len < 1440; ++j) {
        len += 8 + tmp[j].name.size();
    }
    char buf[len];
    buf[0] = 1;
    tobytes( seqnum, buf + 1);
    buf[5] = (char) (j & 0xFF);
    int i = 6;
    if (len >= 1440)
        j--;

    for (int k = 0; k < j; ++k) {
        cout << tmp[k].ip << " " << tmp[k].port << " " << tmp[k].flag << " " << tmp[k].name << endl;
        tobytes_be(tmp[k].ip, buf + i);
        i += 4;
        char b[4];
        tobytes_be(tmp[k].port, b);
        buf[i] = b[2];
        buf[i + 1] = b[3];
        i += 2;
        buf[i] = tmp[k].flag;
        i++;
        buf[i] = (char) (tmp[k].name.size() & 0xFF);
        i++;
        for (int l = 0; l < tmp[k].name.size(); ++l) {
            buf[i] = tmp[k].name[l];
            i++;
        }
        if (flag == 3) {
            len++;
            buf[i] = tmp[k].thread_count;
            i++;
        }
    }
    auto l = socket.send_to(buffer(buf, len), sender_endpoint);
    if (l < len)
        cout << "Not everything sent" <<endl;
}

int now_mils() {
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

void dns::send_request() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        current.clear();
    }
    udp::endpoint endpoint(address::from_string(group_ip), group_port);
    udp::socket* socket = new udp::socket(io_service2, endpoint.protocol());
    cout << "Sent request" << endl;

    char buf[6];
    buf[0] = 0;
    srand ((unsigned int) time(NULL));
    int sn = rand();
    cout << sn << endl;
    tobytes((unsigned int) sn, buf + 1);
    buf[5] = 0;

    //std::lock_guard<std::mutex> lock(mtx);
    curr_seq_num = sn;
    socket->send_to(buffer(buf, 6), endpoint);

    cout << "Waiting for responses" << endl;
    dns_threads.create_thread([this, buf, socket] () { this->process_response(socket, now_mils()); });
}


void dns::process_response(udp::socket* socket, int time) {
    char buf[1440];
    int count = 0;
    int loaded = 0;
    while (count < 10) {
        count++;
        while (loaded < 6)
            loaded += socket->receive(buffer(buf + loaded, (size_t) (1440 - loaded)));
        cout << "Response received" << endl;
        if (buf[0] != 1) {
            cout << "Something went wrong, it's not a response" << endl;
            return;
        }
        unsigned int this_seq_num = toint(buf[1], buf[2], buf[3], buf[4]);
        cout << this_seq_num << " " << curr_seq_num << endl;
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (this_seq_num != curr_seq_num)
                return;
        }
        int i = 6;
        unsigned int answers = toint(buf[5], 0, 0, 0);
        //cout << "Amount of items " << answers << endl;
        for (int j = 0; j < answers && i < 1440; ++j) {
            while (loaded < i + 8) {
                loaded += socket->receive(buffer(buf + loaded, (size_t) (1440 - loaded)));
            }
            string ip = getip(buf[i], buf[i + 1], buf[i + 2], buf[i + 3]);
            i += 4;
            unsigned short port = (unsigned short) toint_be(0, 0, buf[i], buf[i + 1]);
            i += 2;
            char f = buf[i];
            i++;
            unsigned int length = toint(buf[i], 0, 0, 0);
            i++;

            while (loaded < i + length) {
                loaded += socket->receive(buffer(buf + loaded, (size_t) (1440 - loaded)));
            }
            string name(buf + i, length);
            i += length;
            unsigned char threadcount = 0;
            if (f == 3) {
                threadcount = (unsigned char) buf[i];
                i++;
            }

            dns_entry entry = dns_entry(ip, port, f, name, threadcount);
            cout << ip << " " << port << " " << f << " " << length << " " << name << endl;
            {
                std::lock_guard<std::mutex> lock(mtx);
                current.push_back(entry);
            }
        }
        if (loaded > i) {
            cout << "Loaded some from next response " << endl;
            copy_n(buf + i, loaded - i, buf);
            loaded -= i;
        } else {
            loaded = 0;
        }
    }
}

void dns::process_request(boost::array<char, 1440> buf, udp::endpoint sender, udp::endpoint local) {
    unsigned int this_seq_num = toint(buf[1], buf[2], buf[3], buf[4]);
    cout << "Request reseived from " << sender.address().to_string() << " " << sender.port() << " " << this_seq_num << endl;
    if (this_seq_num == curr_seq_num)
        return;
    send_response(this_seq_num, sender, local);
}

void dns::get_nodes() {
    if (last_request == -1) {
        dns_threads.create_thread([this]() { this->listen_dns(); });
    }
    if (last_request == -1 || now_mils() - last_request > timeout_mill) {
        last_request = now_mils();
        send_request();
    }
}

void dns::set_thread_count(unsigned char count) {
    {
        std::lock_guard<std::mutex> lock(mtx);
        this->thread_count = count;
    }
}
