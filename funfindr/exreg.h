#ifndef EXREG_H
#define EXREG_H
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

class exreg
{
    public:
    virtual ~exreg();
    tgui::Gui* gui;
    int num;
    exreg(tgui::Gui*,int);
    void callbackFunc();
    tgui::Button* button_funboolc;
    tgui::Button button_funboolcp;
    void scol();
    int isx;
    int isx0;
};

#endif // EXREG_H
