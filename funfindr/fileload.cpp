#include "fileload.h"
#include "fstream"
#include <iostream>
#include <sstream>
#include <string>
#include "xdata.h"

void fileload::load(std::string pathix){
    std::string myText;
    std::ifstream MyReadFile(pathix);
    std::string myCell;
    xdata::fdata={};
    int ix=0;
    size_t st;
    while (std::getline (MyReadFile, myText)) {

        xdata::fdata.push_back({});
        std::stringstream myLine(myText);
        while (std::getline (myLine, myCell,',')) {
            xdata::fdata[ix].push_back(std::stod(myCell));
        }
        ix++;
}
MyReadFile.close();

};

void fileload::swaprc()
{
    xdata::sfdata.clear();
    for(int ix=0;ix<xdata::fdata[0].size();ix++){
        xdata::sfdata.push_back({});
        for(int jx=0;jx<xdata::fdata.size();jx++){
            xdata::sfdata[ix].push_back({});
        }
    }
    for(int ix=0;ix<xdata::fdata.size();ix++){

        for(int jx=0;jx<xdata::fdata[0].size();jx++){
            xdata::sfdata[jx][ix]=xdata::fdata[ix][jx];
        }
    }

}
