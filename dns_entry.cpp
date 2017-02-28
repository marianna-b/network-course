#include "dns_entry.h"

using namespace std;

dns_entry::dns_entry(string ip, unsigned short port, bool is_prod, string name) {
    this->ip = ip;
    this->port = port;
    this->is_prod = is_prod;
    this->name = name;
}

bool dns_entry::operator==(dns_entry entry) {
    return (ip == entry.ip && port == entry.port);
}