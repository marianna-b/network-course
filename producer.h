#ifndef NETS_PRODUCER_H
#define NETS_PRODUCER_H

#include <string>

class producer {
public:
    producer(unsigned short port);
    void start(std::string);

private:
    unsigned short port;
};


#endif //NETS_PRODUCER_H
