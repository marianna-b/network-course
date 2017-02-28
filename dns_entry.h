#ifndef NETS_DNS_ENTRY_H
#define NETS_DNS_ENTRY_H

#include <string>

struct dns_entry {
public:
    dns_entry(std::string, unsigned short, bool, std::string);
    std::string ip;
    unsigned short port;
    bool is_prod;
    std::string name;

    bool operator==(dns_entry);
};

#endif //NETS_DNS_ENTRY_H
