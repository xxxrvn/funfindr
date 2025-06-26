#ifndef GEN_H
#define GEN_H
#include <vector>
#include "resi.h"
#include <sstream>

class gen
{
    public:

    static std::vector<std::vector<int>> xcode;
    static void xnext();
    static void echo(resi*);
    static void echoli(std::vector<int>, resi*);

    static void showli(std::vector<int>);
    static void show();
    static std::stringstream sss;
};

#endif // GEN_H
