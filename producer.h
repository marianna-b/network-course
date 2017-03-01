#ifndef NETS_PRODUCER_H
#define NETS_PRODUCER_H

#include <string>

class producer {
public:
    producer(std::string, unsigned short port);
    void start(std::string);

private:
    unsigned short port;
    std::string ip;
};


#endif //NETS_PRODUCER_H
