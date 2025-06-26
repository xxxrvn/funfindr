#include "gen.h"
#include "data.h"
#include <iostream>
#include "resi.h"

std::vector<std::vector<int>> gen::xcode= {{0,0,0,0,0}};

void gen::echoli(std::vector<int> line, resi *r){
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

    std::cout
    <<str0<<" "
    <<str1<<" "
    <<str2<<" "
    <<str3<<" "
    <<str4<<" "
    <<std::endl;

    r->funis
    <<str0<<" "
    <<str1<<" "
    <<str2<<" "
    <<str3<<" "
    <<str4<<" "
    <<std::endl;
}

std::stringstream gen::sss;


void gen::showli(std::vector<int> line){

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


    gen::sss
    <<str0<<" "
    <<str1<<" "
    <<str2<<" "
    <<str3<<" "
    <<str4<<" "
    <<std::endl;
}

void gen::echo(resi *r){

    for(std::vector<int> line : gen::xcode){
        echoli(line,r);
    }
}

void gen::show(){
    sss.str("");
    for(std::vector<int> line : gen::xcode){
        showli(line);
    }
}

void gen::xnext(){
    int ix=gen::xcode.size()-1;
    int jx=4;
    while(true){
        if (jx!=0){
            if(data::xfunp[gen::xcode[ix][0]][jx-1]==2)
            {
                if (gen::xcode[ix][jx]!=data::cntval){
                    gen::xcode[ix][jx]++;
                    break;
                }
                else{
                    gen::xcode[ix][jx]=0;
                    jx--;
                }
            }
            if(data::xfunp[gen::xcode[ix][0]][jx-1]==1)
            {
                if (gen::xcode[ix][jx]!=data::cntreg){
                    gen::xcode[ix][jx]++;
                        break;
                }
                else{
                    gen::xcode[ix][jx]=0;
                    jx--;
                }
            }
            if(data::xfunp[gen::xcode[ix][0]][jx-1]==3)
            {
                if (gen::xcode[ix][jx]!=data::cntbor){
                    gen::xcode[ix][jx]++;
                        break;
                }
                else{
                    gen::xcode[ix][jx]=0;
                    jx--;
                }
            }
            if(data::xfunp[gen::xcode[ix][0]][jx-1]==0)
            {
                jx--;
            }

        }
        else{
            if (gen::xcode[ix][0]!=data::cntfun){
                gen::xcode[ix][0]++;
                gen::xcode[ix][1]=0;
                gen::xcode[ix][2]=0;
                gen::xcode[ix][3]=0;
                gen::xcode[ix][4]=0;
                break;
            }
            else{
                gen::xcode[ix]=std::vector<int> {0,0,0,0,0};
                if (ix!=0){
                        ix--;
                jx=4;
                }
                else {
                    gen::xcode.push_back(std::vector<int> {0,0,0,0,0});
                    break;
                }
            }
        }
    }
}
