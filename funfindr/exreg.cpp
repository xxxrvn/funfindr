#include "exreg.h"
#include "sett.h"
#include <windows.h>
#include <unistd.h>
#include "lists.h"
void exreg::callbackFunc(){}

exreg::exreg(tgui::Gui *xgui,int n)
{
    num=n;
    auto* gui=xgui;
    auto button_funboolc = tgui::Button::create();
    std::shared_ptr<tgui::Button> button_funboolcp=button_funboolc;
    gui->add(button_funboolc);
    isx=sett::exregc;
    button_funboolc->setText(std::to_string(num));
    button_funboolc->setSize(24,24);
    button_funboolc->setPosition(100+(num%8)*30,120+int((num / 8+1))*30);
    if (isx==num){
        button_funboolc->getRenderer()->setBackgroundColor(sf::Color(0,255,0,255));
                             button_funboolc->getRenderer()->setBackgroundColorHover(sf::Color(64,255,64,255));
    }else{
                            button_funboolc->getRenderer()->setBackgroundColor(sf::Color(255,0,0,255));
                             button_funboolc->getRenderer()->setBackgroundColorHover(sf::Color(255,64,64,255));}

    button_funboolc->onPress([button_funboolc,this](){
                             isx=num;
                               // sett::ifun[num]=isx;
    if (isx==num){
        button_funboolc->getRenderer()->setBackgroundColor(sf::Color(0,255,0,255));
                             button_funboolc->getRenderer()->setBackgroundColorHover(sf::Color(64,255,64,255));
    }else{
                            button_funboolc->getRenderer()->setBackgroundColor(sf::Color(255,0,0,255));
                             button_funboolc->getRenderer()->setBackgroundColorHover(sf::Color(255,64,64,255));}

                             });
}
void exreg::scol(){
    sett::exregc=isx;
    if (isx==num){
//        button_funboolc->getRenderer()->setBackgroundColor(sf::Color(0,255,0,255));
//                             button_funboolc->getRenderer()->setBackgroundColorHover(sf::Color(64,255,64,255));
//    }else{
//                            button_funboolc->getRenderer()->setBackgroundColor(sf::Color(255,0,0,255));
//                             button_funboolc->getRenderer()->setBackgroundColorHover(sf::Color(255,64,64,255));
//                             }

}
}
exreg::~exreg()
{
    //dtor
}
