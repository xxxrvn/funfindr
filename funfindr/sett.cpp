#include "sett.h"

std::vector<bool> sett::ifun={
        false,//"set reg val"
        true,//"add reg val val",
        true,//false,//"sub reg val val",
        true,//"mul reg val val",
        true,//"div reg val val",
        false,//"pow reg val val",
        false,//"mod reg val val",
        false,//"log reg val",
        false,//"logn reg val val",
        false,//"abs reg val",
        false,//sign
        false,//copysign
        false,//"flr reg val",
        false,//"ceil reg val",
        false,//"rnd reg val",
        false,//"max reg val val",
        false,//"min reg val val",
        false,//"sin reg val",
        false,//"cos reg val",
        false,//"tan reg val",
        false,//"asin reg val",
        false,//"acos reg val",
        false,//"atan reg val",
        false,//"sinh reg val",
        false,//"cosh reg val",
        false,//"tanh reg val",
        false,//"asinh reg val",
        false,//"acosh reg val",
        false,//"atanh reg val",
        false,//"fib reg val",
        false,//lucas
        false,//"prime reg val",
        false,//"ifoe reg reg val val",
        false,//"issmaller reg val val",
        false,//"iseq reg val val",
        false,//"not reg reg",
        false,//"xor reg reg reg",
        false,//"or reg reg reg",
        false,//"and reg reg",
        false,//"suml reg",
        false,//"prodl reg",
        false,//"erf reg val",
        false,//triwave
        false,//cirwave
        false,//hypot
        false,//dist
        false,//"logistic reg val"
        false,//"gamma reg val"
        false,//"harmonic reg val"
        false//initlr
    };
std::vector<bool> sett::ivar={
    false,false,false,false
//"pi","e","gor","row"
};

std::vector<double> sett::parco={1,2,3,4,5,6,7,8,9};
int sett::resco=0;

int sett::exregc=0;

int sett::boregc=0;

int sett::lrlvl=0;
int sett::persivc=0;

int sett::paramsc=0;

int sett::intec=0;

int sett::breakmodeq=0;
int sett::breakmodea=0;

bool sett::swaprcx=false;
