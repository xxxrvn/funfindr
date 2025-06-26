#ifndef MATHFUN_H
#define MATHFUN_H
#include <string>
#include <vector>
#include "resi.h"


class mathfun
{
    public:
       static double dofun(std::string, double, double, double);
       static double doval(std::string);
       static void regwr(std::string,double);
       static void doline(std::vector<int>);
       static void dolines();


       static double residoval(std::string);
       static void resiregwr(std::string,double);
       static void residoline(std::vector<int>);
       static void residolines(resi *r);
};

#endif // MATHFUN_H
