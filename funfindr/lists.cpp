#include "lists.h"


std::vector<std::string> lists::funhlist={
        "set",
        "add",
        "sub",
        "mul",
        "div",

        "pow",
        "mod",
        "log",
        "logn",
        "abs",
        "sign",
        "copysign",

        "flr",
        "ceil",
        "rnd",
        "max",
        "min",

        "sin",
        "cos",
        "tan",
        "asin",
        "acos",

        "atan",
        "sinh",
        "cosh",
        "tanh",
        "asinh",

        "acosh",
        "atanh",
        "fib",
        "lucas",
        "prime",
        "ifoe",

        "issmaller",
        "isequal",
        "not",
        "xor",

        "or",
        "and",
        "suml",
        "prodl",
        "erf",

        "triwave",
        "cirwave",
        "hypot",
        "dist",

        "logistic",
        "gamma",
        "harmonic",
        "initlr"
    };


std::vector<std::string> lists::varlist={
        "pi","e","gor","row"
    };

std::vector<std::string> lists::reglist={
        "res","reg1","reg2","reg3","reg4"
    };
std::vector<std::string> lists::lrlist={
        "lr1","lr2","lr3","lr4","lr5"
    };
std::vector<std::string> lists::pvlist={
        "pv1","pv2","pv3","pv4","pv5"
    };
std::vector<std::string> lists::parlist={
        "fp1","fp2","fp3","fp4","fp5","fp6","fp7","fp8","fp9"
    };


std::vector<std::string> lists::borlist={
        "bor1","bor2","bor3","bor4"
    };

std::vector<std::vector<int>> lists::funplist={
        {1,2,0,0},//set
        {1,2,2,0},//add
        {1,2,2,0},//sub
        {1,2,2,0},//mul
        {1,2,2,0},//div

        {1,2,2,0},//pow
        {1,2,2,0},//"mod reg val val",
        {1,2,0,0},//"log reg val",
        {1,2,2,0},//"logn reg val val",
        {1,2,0,0},//"abs reg val",
        {1,2,0,0},//"sign reg val",

        {1,2,2,0},//"copysign

        {1,2,0,0},//"flr reg val",
        {1,2,0,0},//"ceil reg val",
        {1,2,0,0},//"rnd reg val",
        {1,2,2,0},//"max reg val val",
        {1,2,2,0},//"min reg val val",

        {1,2,0,0},//"sin reg val",
        {1,2,0,0},//"cos reg val",
        {1,2,0,0},//"tan reg val",
        {1,2,0,0},//"asin reg val",
        {1,2,0,0},//"acos reg val",

        {1,2,0,0},//"atan reg val",
        {1,2,0,0},//"sinh reg val",
        {1,2,0,0},//"cosh reg val",
        {1,2,0,0},//"tanh reg val",
        {1,2,0,0},//"asinh reg val",

        {1,2,0,0},//"acosh reg val",
        {1,2,0,0},//"atanh reg val",
        {1,2,0,0},//"fib reg val",
        {1,2,0,0},//"lucas reg val",


        {1,2,0,0},//"prime reg val",
        {1,3,2,2},//"ifoe reg reg val val",

        {3,2,2,0},//"issmaller  reg val val",
        {3,2,2,0},//"isequal reg val val",
        {3,3,0,0},//"not reg reg",
        {3,3,3,0},//"xor reg reg reg",

        {3,3,3,0},//"or reg reg reg",
        {3,3,3,0},//"and reg reg",
        {1,0,0,0},//"suml reg",
        {1,0,0,0},//"prodl reg",
        {1,2,0,0},//"erf reg val",

        {1,2,0,0},//triwave
        {1,2,0,0},//cirwave
        {1,2,2,0},//hypot
        {1,2,2,0},//dist



        {1,2,0,0},//"logistic reg val"
        {1,2,0,0},//"gamma reg val"
        {1,2,0,0},//"harmonic reg val"
        {0,2,0,0},//"initlr  val"
    };
