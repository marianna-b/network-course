#ifndef NETS_CONSUMER_H
#define NETS_CONSUMER_H


#include "dns.h"
#include <string>

class consumer {

public:
    consumer(std::string ip, unsigned short port);
    void start(std::string);

private:
    unsigned short port;
    std::string ip;
};


#endif //NETS_CONSUMER_H
