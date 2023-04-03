#ifndef UPRINT_H
#define UPRINT_H

#include <string>

void PrintCmt(std::string& s, const std::string& s0, int x);
void PrintN(std::string& s, int n, int x, int w, bool check);
void PrintR(std::string& s, double r, int x, int w, int p, bool check);
void PrintB(std::string& s, int b, int x);
void PrintC(std::string& s, char c, int x);
void PrintS(std::string& s, const std::string& s1, int x, int w);

#endif
