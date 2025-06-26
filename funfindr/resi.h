#ifndef RESI_H
#define RESI_H
#include <sstream>
#include <vector>


class resi
{
    public:
        resi();
        double err;
        std::stringstream funis;
        std::vector<std::vector<int>> xcode;
        std::vector<double> xres;
        std::vector<double> xerr;
    protected:

    private:
};

#endif // RESI_H
