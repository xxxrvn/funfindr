#ifndef LISTS_CPP
#define LISTS_CPP


class lists
{
    #include <iostream>
#include <vector>

using namespace std;
struct lists{
    const string funlist[40]={
        "set reg val",
        "add reg val val",
        "sub reg val val",
        "mul reg val val",
        "div reg val val",
        "pow reg val val",
        "mod reg val val",
        "log reg val",
        "logn reg val val",
        "abs reg val",
        "flr reg val",
        "ceil reg val",
        "rnd reg val",
        "max reg val val",
        "min reg val val",
        "sin reg val",
        "cos reg val",
        "tan reg val",
        "asin reg val",
        "acos reg val",
        "atan reg val",
        "sinh reg val",
        "cosh reg val",
        "tanh reg val",
        "asinh reg val",
        "acosh reg val",
        "atanh reg val",
        "fib reg val",
        "prime reg val",
        "ifoe reg reg val val",
        "issm reg val val",
        "iseq reg val val",
        "not reg reg",
        "xor reg reg reg",
        "or reg reg reg",
        "and reg reg",
        "suml reg",
        "prodl reg",
        "real reg val",
        "imag reg val"
    };
    string varlist[4]={
        "pi","e","gor","row"
    };

    string reglist[5]={
        "res","reg1","reg2","reg3","reg4"
    };
    string lrlist[5]={
        "lr1","lr2","lr3","lr4","lr5"
    };

};

};

#endif // LISTS_CPP
