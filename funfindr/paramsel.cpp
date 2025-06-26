#include "paramsel.h"
#include "sett.h"
#include <windows.h>
#include <unistd.h>
#include "lists.h"

paramsel::paramsel(int n)
{
    num=n;
    tgui::ComboBox::Ptr  cbox_paramsel= tgui::ComboBox::create();
    cbox_paramsel->setSize(100,24);
    cbox_paramsel->setPosition(430+(num%8)*110,50);
}
paramsel::~paramsel()
{


}
void paramsel::des(paramsel p){

}
