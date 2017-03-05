#include <iostream>
#include <string>
#include "consumer.h"
#include "producer.h"
#include "utils.h"
#include "lua_executor.h"
#include "executor_client.h"

using namespace std;

int main() {
    string ip, option;
    cin >> ip;

    if (ip == "client") {
        executor_client client;
        string res;
        while ((res = client.execute("return 595")) == "")
            sleep(3);
        cout << res << endl;
        return 0;
    }

    cin >> option;
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
    if (option == "executor1") {
        lua_executor executor(ip, 11555, 10);
        executor.start("executor1");
    }
    if (option == "executor2") {
        lua_executor executor(ip, 12555, 10);
        executor.start("executor2");
    }
    return 0;
}