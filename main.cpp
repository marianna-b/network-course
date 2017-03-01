#include <iostream>
#include <string>
#include "consumer.h"
#include "producer.h"
#include "utils.h"

using namespace std;

int main() {
    string ip, option;
    cin >> ip >> option;
    if (option == "consumer") {
        consumer consumer1(ip, 15557);
        consumer1.start("consumer1");
    }
    if (option == "producer1") {
        producer producer1(ip, 16555);
        producer1.start("producer1");
    }
    if (option == "producer2") {
        producer producer1(ip, 17555);
        producer1.start("producer2");
    }
    return 0;
}