#include "mathfun.h"
#include <cmath>
#include <string>
#include "cdata.h"
#include "cresi.h"
#include "data.h"
#include "gen.h"
#include <iostream>
#include "xdata.h"
#include <cstring>
#include "exfun.h"
#define _USE_MATH_DEFINES

double mathfun::dofun(std::string fun, double a, double b, double c){
    if(exfun::fastrcmp(fun,"set"))return a;
    if(exfun::fastrcmp(fun,"add"))return a+b;
    if(exfun::fastrcmp(fun,"sub"))return a-b;
    if(exfun::fastrcmp(fun,"mul"))return a*b;
    if(exfun::fastrcmp(fun,"div"))return a/b;
    if(exfun::fastrcmp(fun,"pow"))return pow(a,b);

    if(exfun::fastrcmp(fun,"triwave"))return (2*fabs(fmod(a,2)-1))-1;
    if(exfun::fastrcmp(fun,"cirwave")) return copysign(sqrt(1-pow((fmod(2*a,2)-1),2)),fmod((2*a),4)-2);

    if(exfun::fastrcmp(fun,"sin"))return sin(a);
    if(exfun::fastrcmp(fun,"cos"))return cos(a);
    if(exfun::fastrcmp(fun,"tanh"))return tanh(a);
    if(exfun::fastrcmp(fun,"sinh"))return sinh(a);
    if(exfun::fastrcmp(fun,"cosh"))return cosh(a);
    if(exfun::fastrcmp(fun,"tan"))return tan(a);

    if(exfun::fastrcmp(fun,"asin"))return asin(a);
    if(exfun::fastrcmp(fun,"acos"))return acos(a);
    if(exfun::fastrcmp(fun,"atanh"))return atanh(a);
    if(exfun::fastrcmp(fun,"asinh"))return asinh(a);
    if(exfun::fastrcmp(fun,"acosh"))return acosh(a);
    if(exfun::fastrcmp(fun,"atan"))return atan(a);

    if(exfun::fastrcmp(fun,"log")) return log(a);
    if(exfun::fastrcmp(fun,"logn")) return log(a)/log(b);

    if(exfun::fastrcmp(fun,"abs")) return fabs(a);
    if(exfun::fastrcmp(fun,"sign")) return copysign(1,a);
    if(exfun::fastrcmp(fun,"copysign")) return copysign(a,b);


    if(exfun::fastrcmp(fun,"hypot"))return sqrt(pow(a,2)+pow(b,2));

    if(exfun::fastrcmp(fun,"dist"))return fabs(a-b);

    if(exfun::fastrcmp(fun,"lucas")){
        return (
                pow(1+sqrt(5)/2,a)+pow(1-sqrt(5)/2,a)
                );
    }
    if(exfun::fastrcmp(fun,"fib")){
        return ((
                pow((1+sqrt(5))/2,a)-(
                pow(2/(1+sqrt(5)),a)*cos(3.14159265358979323846*a))
            )/sqrt(5));
    }
    if(exfun::fastrcmp(fun,"logistic")){
        if (a > 1000) return 1;
        if (a < -1000) return 0;
        return 1 / (1 + exp(-a));
    }
    if(exfun::fastrcmp(fun,"ifoe")) if(a==1){return b;} else {return c;}
    if(exfun::fastrcmp(fun,"not")) if(a==0){return 1;} else {return 0;}
    if(exfun::fastrcmp(fun,"isequal")) if(a==b){return 1;} else {return 0;}
    if(exfun::fastrcmp(fun,"issmaller")) if(a<b){return 1;} else {return 0;}

    if(exfun::fastrcmp(fun,"gamma")) return tgamma(a);
    if(exfun::fastrcmp(fun,"mod")) return fmod(a,b);
    if(exfun::fastrcmp(fun,"erf")) return erf(a);
    if(exfun::fastrcmp(fun,"suml")){
            double sumd=0;
        for(int ix=0;ix<=cdata::row;ix++){
            sumd+=xdata::results[ix];
        }
            return sumd;
    }
    if(exfun::fastrcmp(fun,"prodl")){
            double prodd=0;
        for(int ix=0;ix<=cdata::row;ix++){
            prodd+=xdata::results[ix];
        }
            return prodd;
    }
    if(exfun::fastrcmp(fun,"initlr")) {
            if (cdata::row==0){
                cdata::lr1=a;
                cdata::lr2=a;
                cdata::lr3=a;
                cdata::lr4=a;
                cdata::lr5=a;
            }
            return 0;}

    return 0;
}

double mathfun::doval(std::string val){

    if(exfun::fastrcmp(val,"res"))return cdata::res;
    if(exfun::fastrcmp(val,"row"))return cdata::row;
    if(exfun::fastrcmp(val,"reg1"))return cdata::reg1;
    if(exfun::fastrcmp(val,"reg2"))return cdata::reg2;
    if(exfun::fastrcmp(val,"reg3"))return cdata::reg3;
    if(exfun::fastrcmp(val,"reg4"))return cdata::reg4;

    if(exfun::fastrcmp(val,"bor1")){return cdata::bor1;}
    if(exfun::fastrcmp(val,"bor2")){return cdata::bor2;}
    if(exfun::fastrcmp(val,"bor3")){return cdata::bor3;}
    if(exfun::fastrcmp(val,"bor4")){return cdata::bor4;}

    if(exfun::fastrcmp(val,"fp1"))return cdata::fp1;
    if(exfun::fastrcmp(val,"fp2"))return cdata::fp2;
    if(exfun::fastrcmp(val,"fp3"))return cdata::fp3;
    if(exfun::fastrcmp(val,"fp4"))return cdata::fp4;
    if(exfun::fastrcmp(val,"fp5"))return cdata::fp5;
    if(exfun::fastrcmp(val,"fp6"))return cdata::fp6;
    if(exfun::fastrcmp(val,"fp7"))return cdata::fp7;
    if(exfun::fastrcmp(val,"fp8"))return cdata::fp8;
    if(exfun::fastrcmp(val,"fp9"))return cdata::fp9;

    if(exfun::fastrcmp(val,"lr1")) return cdata::lr1;
    if(exfun::fastrcmp(val,"lr2")) return cdata::lr2;
    if(exfun::fastrcmp(val,"lr3")) return cdata::lr3;
    if(exfun::fastrcmp(val,"lr4")) return cdata::lr4;
    if(exfun::fastrcmp(val,"lr5")) return cdata::lr5;

    if(exfun::fastrcmp(val,"pv1")) return cdata::pv1;
    if(exfun::fastrcmp(val,"pv2")) return cdata::pv2;
    if(exfun::fastrcmp(val,"pv3")) return cdata::pv3;
    if(exfun::fastrcmp(val,"pv4")) return cdata::pv4;
    if(exfun::fastrcmp(val,"pv5")) return cdata::pv5;

    if(exfun::fastrcmp(val,"e")) return 2.71828182845904523536;
    if(exfun::fastrcmp(val,"pi")) return 3.14159265358979323846;
    if(exfun::fastrcmp(val,"gor")) return 1.6180339887498948482;

    return stoi("0"+val);
}



double mathfun::residoval(std::string val){

    if(exfun::fastrcmp(val,"res"))return cresi::res;
    if(exfun::fastrcmp(val,"row"))return cresi::row;
    if(exfun::fastrcmp(val,"reg1"))return cresi::reg1;
    if(exfun::fastrcmp(val,"reg2"))return cresi::reg2;
    if(exfun::fastrcmp(val,"reg3"))return cresi::reg3;
    if(exfun::fastrcmp(val,"reg4"))return cresi::reg4;

    if(exfun::fastrcmp(val,"bor1")){return cresi::bor1;}
    if(exfun::fastrcmp(val,"bor2")){return cresi::bor2;}
    if(exfun::fastrcmp(val,"bor3")){return cresi::bor3;}
    if(exfun::fastrcmp(val,"bor4")){return cresi::bor4;}

    if(exfun::fastrcmp(val,"fp1"))return cresi::fp1;
    if(exfun::fastrcmp(val,"fp2"))return cresi::fp2;
    if(exfun::fastrcmp(val,"fp3"))return cresi::fp3;
    if(exfun::fastrcmp(val,"fp4"))return cresi::fp4;
    if(exfun::fastrcmp(val,"fp5"))return cresi::fp5;
    if(exfun::fastrcmp(val,"fp6"))return cresi::fp6;
    if(exfun::fastrcmp(val,"fp7"))return cresi::fp7;
    if(exfun::fastrcmp(val,"fp8"))return cresi::fp8;
    if(exfun::fastrcmp(val,"fp9"))return cresi::fp9;

    if(exfun::fastrcmp(val,"lr1")) return cresi::lr1;
    if(exfun::fastrcmp(val,"lr2")) return cresi::lr2;
    if(exfun::fastrcmp(val,"lr3")) return cresi::lr3;
    if(exfun::fastrcmp(val,"lr4")) return cresi::lr4;
    if(exfun::fastrcmp(val,"lr5")) return cresi::lr5;

    if(exfun::fastrcmp(val,"pv1")) return cresi::pv1;
    if(exfun::fastrcmp(val,"pv2")) return cresi::pv2;
    if(exfun::fastrcmp(val,"pv3")) return cresi::pv3;
    if(exfun::fastrcmp(val,"pv4")) return cresi::pv4;
    if(exfun::fastrcmp(val,"pv5")) return cresi::pv5;

    if(exfun::fastrcmp(val,"e")) return 2.71828182845904523536;
    if(exfun::fastrcmp(val,"pi")) return 3.14159265358979323846;
    if(exfun::fastrcmp(val,"gor")) return 1.6180339887498948482;

    return stoi("0"+val);
}




void mathfun::regwr(std::string reg, double a){
    if(exfun::fastrcmp(reg,"res")){cdata::res=a;return;}
    if(exfun::fastrcmp(reg,"reg1")){cdata::reg1=a;return;}
    if(exfun::fastrcmp(reg,"reg2")){cdata::reg2=a;return;}
    if(exfun::fastrcmp(reg,"reg3")){cdata::reg3=a;return;}
    if(exfun::fastrcmp(reg,"reg4")){cdata::reg4=a;return;}

    if(exfun::fastrcmp(reg,"bor1")){cdata::bor1=a;return;}
    if(exfun::fastrcmp(reg,"bor2")){cdata::bor2=a;return;}
    if(exfun::fastrcmp(reg,"bor3")){cdata::bor3=a;return;}
    if(exfun::fastrcmp(reg,"bor4")){cdata::bor4=a;return;}

    if(exfun::fastrcmp(reg,"pv1")){cdata::pv1=a;return;}
    if(exfun::fastrcmp(reg,"pv2")){cdata::pv2=a;return;}
    if(exfun::fastrcmp(reg,"pv3")){cdata::pv3=a;return;}
    if(exfun::fastrcmp(reg,"pv4")){cdata::pv4=a;return;}
    if(exfun::fastrcmp(reg,"pv5")){cdata::pv5=a;return;}

}

void mathfun::resiregwr(std::string reg, double a){
    if(exfun::fastrcmp(reg,"res")){cresi::res=a;return;}
    if(exfun::fastrcmp(reg,"reg1")){cresi::reg1=a;return;}
    if(exfun::fastrcmp(reg,"reg2")){cresi::reg2=a;return;}
    if(exfun::fastrcmp(reg,"reg3")){cresi::reg3=a;return;}
    if(exfun::fastrcmp(reg,"reg4")){cresi::reg4=a;return;}

    if(exfun::fastrcmp(reg,"bor1")){cresi::bor1=a;return;}
    if(exfun::fastrcmp(reg,"bor2")){cresi::bor2=a;return;}
    if(exfun::fastrcmp(reg,"bor3")){cresi::bor3=a;return;}
    if(exfun::fastrcmp(reg,"bor4")){cresi::bor4=a;return;}

    if(exfun::fastrcmp(reg,"pv1")){cresi::pv1=a;return;}
    if(exfun::fastrcmp(reg,"pv2")){cresi::pv2=a;return;}
    if(exfun::fastrcmp(reg,"pv3")){cresi::pv3=a;return;}
    if(exfun::fastrcmp(reg,"pv4")){cresi::pv4=a;return;}
    if(exfun::fastrcmp(reg,"pv5")){cresi::pv5=a;return;}

}


void mathfun::doline(std::vector<int> line){

    std::string str0=data::xfun[line[0]];

    std::string str1=data::xreg[line[1]];
    if(data::xfunp[line[0]][0]==3)str1=data::xbor[line[1]];
    if(data::xfunp[line[0]][0]==0)str1="";
    std::string str2=data::xval[line[2]];
    if(data::xfunp[line[0]][1]==3)str2=data::xbor[line[2]];
    if(data::xfunp[line[0]][1]==0)str2="";
    std::string str3=data::xval[line[3]];
    if(data::xfunp[line[0]][2]==3)str3=data::xbor[line[3]];
    if(data::xfunp[line[0]][2]==0)str3="";
    std::string str4=data::xval[line[4]];
    if(data::xfunp[line[0]][3]==3)str4=data::xbor[line[4]];
    if(data::xfunp[line[0]][3]==0)str4="";

    regwr(str1
          ,
          dofun(str0,
              doval(str2),
              doval(str3),
              doval(str4)
            )
          );

}

void mathfun::residoline(std::vector<int> line){

    std::string str0=data::xfun[line[0]];

    std::string str1=data::xreg[line[1]];
    if(data::xfunp[line[0]][0]==3)str1=data::xbor[line[1]];
    if(data::xfunp[line[0]][0]==0)str1="";
    std::string str2=data::xval[line[2]];
    if(data::xfunp[line[0]][1]==3)str2=data::xbor[line[2]];
    if(data::xfunp[line[0]][1]==0)str2="";
    std::string str3=data::xval[line[3]];
    if(data::xfunp[line[0]][2]==3)str3=data::xbor[line[3]];
    if(data::xfunp[line[0]][2]==0)str3="";
    std::string str4=data::xval[line[4]];
    if(data::xfunp[line[0]][3]==3)str4=data::xbor[line[4]];
    if(data::xfunp[line[0]][3]==0)str4="";

    resiregwr(str1
          ,
          dofun(str0,
              residoval(str2),
              residoval(str3),
              residoval(str4)
            )
          );
}

void mathfun::dolines(){
    for(std::vector<int> line : gen::xcode){
        doline(line);
        //if(line==std::vector<int> {1,0,0,0,0}) std::cout<<++i<<std::endl;
    }
}
void mathfun::residolines(resi *r){
    for(std::vector<int> line : r->xcode){
        residoline(line);
        //if(line==std::vector<int> {1,0,0,0,0}) std::cout<<++i<<std::endl;
    }
}
