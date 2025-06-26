#ifndef VARBOOL_H
#define VARBOOL_H
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>


class varbool
{
    public:
    virtual ~varbool();
    tgui::Gui* gui;
    int num;
    varbool(tgui::Gui*,int);
    void callbackFunc();
    tgui::Button button_funboolc;
    void scol();
    bool isx;
};

#endif // VARBOOL_H
