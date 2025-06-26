#include "tcalc.h"
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
#include "rdata.h"

void tcalc::calc()
{


    int row=0;
    double rowerrsum=0;
    double avgerr=100000;
    data::tries=0;

    while(true){

        row=0;
        rowerrsum=0;
        cdata::lr1=0;
        cdata::lr2=0;
        cdata::lr3=0;
        cdata::lr4=0;
        cdata::lr5=0;

        cdata::pv1=0;
        cdata::pv2=0;
        cdata::pv3=0;
        cdata::pv4=0;
        cdata::pv5=0;
        std::vector<double> xres={};
        std::vector<double> xerr={};

        data::tries++;
        while(true){
            cdata::row=row;

            cdata::res=0;
            cdata::reg1=0;
            cdata::reg2=0;
            cdata::reg3=0;
            cdata::reg4=0;

            cdata::bor1=0;
            cdata::bor2=0;
            cdata::bor3=0;
            cdata::bor4=0;

            cdata::lr5=cdata::lr4;
            cdata::lr4=cdata::lr3;
            cdata::lr3=cdata::lr2;
            cdata::lr2=cdata::lr1;


            if(row!=0) cdata::lr1=xdata::results[row-1];

            if (sett::paramsc>=1) cdata::fp1=xdata::pars[0][row];
            if (sett::paramsc>=2) cdata::fp2=xdata::pars[1][row];
            if (sett::paramsc>=3)cdata::fp3=xdata::pars[2][row];
            if (sett::paramsc>=4)cdata::fp4=xdata::pars[3][row];
            if (sett::paramsc>=5)cdata::fp5=xdata::pars[4][row];
            if (sett::paramsc>=6)cdata::fp6=xdata::pars[5][row];
            if (sett::paramsc>=7)cdata::fp7=xdata::pars[6][row];
            if (sett::paramsc>=8)cdata::fp8=xdata::pars[7][row];
            if (sett::paramsc>=9)cdata::fp9=xdata::pars[8][row];


            mathfun::dolines();
            if(fabs(cdata::res-xdata::results[row])>(avgerr*sett::breakmodeq+sett::breakmodea)){break;}
            if(fabs(cdata::res-xdata::results[row])<0){break;}
            rowerrsum+=fabs(cdata::res-xdata::results[row]);
            if(rowerrsum<0)break;
            xres.push_back(cdata::res);
            xerr.push_back(fabs(cdata::res-xdata::results[row]));


            if(row==xdata::results.size()-1){
                //std::cout << std::setprecision(10) << (rowerrsum/(row+1)) <<endl<<endl;
                //gen::echo();
                //std::cout<<endl<<endl;
                if(rowerrsum/(row+1)<0){break;}
                if(rowerrsum/(row+1)<avgerr*0.999999){

                    rdata::resis.push_back(new resi());
                    avgerr=rowerrsum/(row+1);
                    rdata::resis[rdata::resis.size()-1]->err=avgerr;
                    rdata::resis[rdata::resis.size()-1]->xres=xres;

                    rdata::resis[rdata::resis.size()-1]->xerr=xerr;
                    std::cout << std::setprecision(10) << avgerr<< " "
                    << data::tries <<std::endl<<std::endl;
                    gen::echo(rdata::resis[rdata::resis.size()-1]);
                    std::cout<<std::endl<<std::endl;

                }

                break;
            }
            row++;

        }
            gen::xnext();
            gen::show();

    }


}
