#include "varbool.h"
#include "sett.h"
#include <windows.h>
#include <unistd.h>
#include "lists.h"
void varbool::callbackFunc(){}

varbool::varbool(tgui::Gui *xgui,int n)
{
    num=n;
    auto* gui=xgui;
    auto button_funboolc = tgui::Button::create();
    gui->add(button_funboolc);
    isx=sett::ivar[num];
    button_funboolc->setText(lists::varlist[num]);
    button_funboolc->setSize(100,24);
    button_funboolc->setPosition(100+(num%8)*110,440+int((num / 8+1))*30);
    if (isx){
        button_funboolc->getRenderer()->setBackgroundColor(sf::Color(0,255,0,255));
                             button_funboolc->getRenderer()->setBackgroundColorHover(sf::Color(64,255,64,255));
    }else{
                            button_funboolc->getRenderer()->setBackgroundColor(sf::Color(255,0,0,255));
                             button_funboolc->getRenderer()->setBackgroundColorHover(sf::Color(255,64,64,255));}

    button_funboolc->onPress([button_funboolc,this](){
                             isx=!isx;
                               // sett::ifun[num]=isx;
    if (isx){
        button_funboolc->getRenderer()->setBackgroundColor(sf::Color(0,255,0,255));
                             button_funboolc->getRenderer()->setBackgroundColorHover(sf::Color(64,255,64,255));
    }else{
                            button_funboolc->getRenderer()->setBackgroundColor(sf::Color(255,0,0,255));
                             button_funboolc->getRenderer()->setBackgroundColorHover(sf::Color(255,64,64,255));}

                             });
}
void varbool::scol(){
    sett::ivar[num]=isx;
}
varbool::~varbool()
{
    //dtor
}
