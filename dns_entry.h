#ifndef NETS_DNS_ENTRY_H
#define NETS_DNS_ENTRY_H

#include <string>

struct dns_entry {
public:
    dns_entry(std::string, unsigned short, char, std::string, unsigned char);
    std::string ip;
    unsigned short port;
    std::string name;
    char flag;
    unsigned char thread_count;

    bool operator==(dns_entry);
};

#endif //NETS_DNS_ENTRY_H
