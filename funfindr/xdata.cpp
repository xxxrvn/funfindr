#include "xdata.h"
#include <vector>


int xdata::colz=0;
int xdata::rowz=0;
std::string xdata::filepo="";

std::vector<std::vector<double>> xdata::fdata={};

std::vector<std::vector<double>> xdata::sfdata={};
std::vector<double> xdata::results={};

std::vector<std::vector<double>> xdata::pars={{0},{0},{0},{0},{0},{0},{0},{0}};
