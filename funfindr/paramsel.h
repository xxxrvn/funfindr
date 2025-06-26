#ifndef PARAMSEL_H
#define PARAMSEL_H
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>


class paramsel
{
    public:
    virtual ~paramsel();
    int num;
    paramsel(int);
    void callbackFunc();
    tgui::ComboBox::Ptr cbox_paramsel;
    void scol();
    static void des(paramsel);
};

#endif // PARAMSEL_H
