#ifndef NETS_CONSUMER_H
#define NETS_CONSUMER_H


#include "dns.h"

class consumer {

public:
    consumer(unsigned short port);
    void start(std::string);

private:
    unsigned short port;
};


#endif //NETS_CONSUMER_H
