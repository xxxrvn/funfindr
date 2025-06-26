#ifndef DATA_H
#define DATA_H
#include <vector>
#include <string>
class data
{
    public:
    static int bgnint;
    static int cntfun;
    static int cntreg;
    static int cntval;
    static int cntbor;
    static int tries;
    static std::vector<std::string> xfun;
    static std::vector<std::string> xreg;
    static std::vector<std::string> xval;

    static std::vector<std::string> xbor;

    static std::vector<std::vector<int>> xfunp;
};

#endif // DATA_H
