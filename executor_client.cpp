#include <boost/asio.hpp>
#include <iostream>
#include "executor_client.h"
#include "dns.h"
#include "utils.h"

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;


std::string executor_client::execute(std::string code) {
    io_service io_service2;

    dns dns_service("client", 0, "", 0, 0);
    dns_service.send_request();

    sleep(3);
    vector<dns_entry> list(dns_service.current);

    int idx = -1;
    cout << "Nodes" << endl;
    for (int i = 0; i < list.size(); i++) {
        cout <<  list[i].name << " " << list[i].ip << " " <<  list[i].port << " " <<  (unsigned int)list[i].flag << " " << (unsigned int)list[i].thread_count << endl;
        if (list[i].flag != 3)
            continue;
        if (idx == -1)
            idx = i;
        if (list[i].thread_count > list[idx].thread_count)
            idx = i;
    }
    if (idx == -1) {
        cout << "No executors available" << endl;
        return "";
    }
    cout << list[idx].name << endl;
    tcp::socket socket(io_service2);
    socket.connect(tcp::endpoint(address::from_string(list[idx].ip), list[idx].port));
    cout << "Connected" << endl;
    int startT = now_mils();
    char b[4];
    tobytes((int) code.size(), b);
    write(socket, buffer(b, 4), transfer_all());
    write(socket, buffer(code), transfer_all());


    char len[4];
    size_t bytes_read = read(socket, buffer(len, 4), transfer_all());
    if (bytes_read < 4)
        return "error";
    int lenstr = tosigint(len);
    bytes_read = read(socket, buffer(len, 4), transfer_all());
    if (bytes_read < 4)
        return "error";
    int time = toint(len);


    if (lenstr == -1)
        return "error";
    char str[lenstr];
    size_t lenfile = read(socket, buffer(str, (size_t) lenstr), transfer_all());
    cout << lenstr << " " << time << " " << now_mils() - startT <<  endl;
    return string(str, lenfile);
}
