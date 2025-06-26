#include <iostream>
#include <vector>
#include "data.h"
#include "gen.h"
#include "cdata.h"
#include "xdata.h"
#include "mathfun.h"
#include <cmath>
#include <iomanip>
#include "lists.h"
#include "sfmlman.h"
#include "sett.h"
#include "sfmlres.h"
using namespace std;




int main()
{
    while(true){
    sfmlman::start();

    if(sett::swaprcx){
                xdata::results=xdata::fdata[sett::resco];
            }else{
                xdata::results=xdata::sfdata[sett::resco];
            }

    for(int ix=0;ix<sett::paramsc;ix++){
            if(sett::swaprcx){
                xdata::pars[ix]=xdata::fdata[sett::parco[ix]];
            }else{
                xdata::pars[ix]=xdata::sfdata[sett::parco[ix]];
            }
    }

data::xfun={};data::xfunp={};
    for(int ox=0;ox<sett::ifun.size();ox++)
    {
            if(sett::ifun[ox]){
                    data::xfun.push_back(lists::funhlist[ox]);
                    data::xfunp.push_back(lists::funplist[ox]);
            }
    }
    data::cntfun=data::xfun.size()-1;

        data::xreg={};data::xval={};data::xbor={};
    for(int ox=0;ox<sett::exregc+1;ox++)
    {
                    data::xreg.push_back(lists::reglist[ox]);

                    data::xval.push_back(lists::reglist[ox]);
    }

    for(int ox=0;ox<sett::boregc+1;ox++)
    {
                    data::xbor.push_back(lists::borlist[ox]);

    }


    for(int ox=0;ox<sett::paramsc;ox++)
    {
                    data::xval.push_back(lists::parlist[ox]);
    }

    for(int ox=0;ox<sett::ivar.size();ox++)
    {
            if(sett::ivar[ox]){
                    data::xval.push_back(lists::varlist[ox]);
            }
    }
    for(int ox=0;ox<sett::lrlvl;ox++)
    {
                    data::xval.push_back(lists::lrlist[ox]);

    }
    for(int ox=0;ox<sett::persivc;ox++)
    {
                    data::xval.push_back(lists::pvlist[ox]);
                    data::xreg.push_back(lists::pvlist[ox]);

    }
    data::bgnint=data::xval.size()-1;

    for(int ox=0;ox<sett::intec;ox++)
    {
                    data::xval.push_back(std::to_string(ox));
    }


    data::cntval=data::xval.size()-1;

    data::cntreg=data::xreg.size()-1;

    data::cntbor=data::xbor.size()-1;

    sfmlres::start();
    }
}





