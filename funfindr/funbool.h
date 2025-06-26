#ifndef FUNBOOL_H
#define FUNBOOL_H
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>



class funbool
{
    public:
    virtual ~funbool();
    tgui::Gui* gui;
    int num;
    funbool(tgui::Gui*,int);
    void callbackFunc();
    tgui::Button button_funboolc;
    void scol();
    bool isx;
};

#endif // FUNBOOL_H
