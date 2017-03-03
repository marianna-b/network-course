#include <sstream>
#include <netinet/in.h>
#include "utils.h"

unsigned int toint(char* bytes) {
    return *((unsigned int*) bytes);
}

int tosigint(char* bytes) {
    return *((int*) bytes);
}

unsigned int toint(char bytes0, char bytes1, char bytes2, char bytes3) {
    char b[4] = {bytes0, bytes1, bytes2, bytes3};
    return toint(b);
}

unsigned int toint_be(char* b) {
    return toint_be(b[0], b[1], b[2], b[3]);
}

unsigned int toint_be(char bytes0, char bytes1, char bytes2, char bytes3) {
    char b[4] = {bytes3, bytes2, bytes1, bytes0};
    return toint(b);
}

void tobytes(unsigned int nint, char* res) {
    *((unsigned int*) res) = nint;
}

void tobytessig(int nint, char* res) {
    *((int*) res) = nint;
}

std::string getip(char* bytes) {
    return getip(bytes[0], bytes[1], bytes[2], bytes[3]);
}

std::string getip(char b0, char b1, char b2, char b3) {
    char result[16];
    sprintf(result, "%d.%d.%d.%d", b0 & 0xFF, b1 & 0xFF, b2 & 0xFF, b3 & 0xFF);
    return std::string(result);
}
void tobytes_be(unsigned int nint, char* res) {
    *((unsigned int*) res) = htonl(nint);
}

void tobytes_be(std::string ip, char* res) {
    std::stringstream s(ip);
    int a,b,c,d;
    char ch;
    s >> a >> ch >> b >> ch >> c >> ch >> d;
    res[0] = (char) (a & 0xff);
    res[1] = (char) (b & 0xff);
    res[2] = (char) (c & 0xff);
    res[3] = (char) (d & 0xff);
}
