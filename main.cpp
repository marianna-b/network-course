#include <iostream>
#include <string>
#include "consumer.h"
#include "producer.h"
#include "utils.h"

using namespace std;

int main() {
    string option;
    cin >> option;
    if (option == "consumer") {
        consumer consumer1(15557);
        consumer1.start("consumer1");
    }
    if (option == "producer") {
        producer producer1(16555);
        producer1.start("producer1");
    }
    return 0;
}