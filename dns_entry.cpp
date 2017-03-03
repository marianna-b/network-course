#include "dns_entry.h"

using namespace std;

dns_entry::dns_entry(string ip, unsigned short port, char flag, string name) {
    this->ip = ip;
    this->port = port;
    this->flag = flag;
    this->name = name;
}

bool dns_entry::operator==(dns_entry entry) {
    return (ip == entry.ip && port == entry.port);
}