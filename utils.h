#ifndef NETS_UTILS_H
#define NETS_UTILS_H

#include <string>

unsigned int toint(char bytes[4]);
unsigned int toint(char bytes0, char bytes1, char bytes2, char bytes3);
std::string getip(char bytes[4]);
std::string getip(char bytes0, char bytes1, char bytes2, char bytes3);
void tobytes(unsigned int nint, char* res);
void tobytes_be(std::string ip, char* res);
void tobytes_be(unsigned int nint, char* res);
unsigned int toint_be(char bytes0, char bytes1, char bytes2, char bytes3);
unsigned int toint_be(char* b);

#endif //NETS_UTILS_H
