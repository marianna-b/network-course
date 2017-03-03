#include "dns_entry.h"

using namespace std;

dns_entry::dns_entry(string ip, unsigned short port, char flag, string name, unsigned char thread_count) {
    this->ip = ip;
    this->port = port;
    this->flag = flag;
    this->name = name;
    this->thread_count = thread_count;
}

bool dns_entry::operator==(dns_entry entry) {
    return (ip == entry.ip && port == entry.port);
}