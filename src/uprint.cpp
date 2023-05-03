#include <string>
#include <sstream>
#include <iomanip>
#include "uprint.h"
#include <codecvt>

std::string FTrueMark = "true ";
std::string FFalseMark = "false";
char FStringQMark = '"';
char FCharQMark = '\'';

// void PrintCmt(std::string &s, const std::string &s0, int x)
// {
//     s.replace(x, s0.size(), s0);
// }

void PrintCmt(std::string &s, const std::string &s0, int x)
{
    // Convert input string to wide character encoding
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring ws = converter.from_bytes(s);
    std::wstring ws0 = converter.from_bytes(s0);

    // Replacement operation in wide character encoding
    ws.replace(x, ws0.size(), ws0);

    // Convert the replaced wide character encoding back to a UTF-8 encoded string
    s = converter.to_bytes(ws);
}

void PrintN(std::string &s, int n, int x, int w, bool check)
{
    std::ostringstream os;
    os << std::setw(w) << n;
    std::string s0 = os.str();
    if (check && s0.size() > w)
    {
        s0.erase(w);
        s0[w - 1] = '*';
    }
    s.replace(x, s0.size(), s0);
}

void PrintR(std::string &s, double r, int x, int w, int p, bool check)
{
    std::ostringstream os;
    os << std::fixed << std::setprecision(p) << std::setw(w) << r;
    std::string s0 = os.str();
    if (check && s0.size() > w)
    {
        s0.erase(w);
        s0[w - 1] = '*';
    }
    s.replace(x, s0.size(), s0);
}

void PrintB(std::string &s, int b, int x)
{
    std::string s0 = (b == 1) ? FTrueMark : FFalseMark;
    s.replace(x, s0.size(), s0);
}

void PrintC(std::string &s, char c, int x)
{
    std::string s0 = FCharQMark + std::string(1, c) + FCharQMark;
    s.replace(x, s0.size(), s0);
}

void PrintS(std::string &s, const std::string &s1, int x, int w)
{
    std::string s0 = FStringQMark + s1 + FStringQMark;
    if (s0.size() > w)
    {
        s0.erase(w);
        s0[w - 1] = '*';
    }
    s.replace(x, s0.size(), s0);
}
