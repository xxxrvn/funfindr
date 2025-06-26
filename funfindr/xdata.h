#ifndef XDATA_H
#define XDATA_H
#include <vector>
#include <string>
class xdata
{
    public:
    static int colz;
    static int rowz;

    static std::string filepo;
    static std::vector<double> results;
    static std::vector<std::vector<double>> pars;

    static std::vector<std::vector<double>> fdata;
    static std::vector<std::vector<double>> sfdata;
};

#endif // XDATA_H
