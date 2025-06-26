#include "sfmlman.h"
#include <imgui.h>
#include <imgui-SFML.h>
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>


#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "funbool.h"
#include "varbool.h"
#include "sett.h"
#include "exreg.h"
#include "lists.h"
#include "paramsel.h"
#include "filesel.h"
#include "xdata.h"
#include <string>
#include <fstream>
#include "fileload.h"

    void sfmlman::start(){
    int a=0;
    sf::RenderWindow window{{1200, 900}, "TGUI example - SFML_GRAPHICS backend"};
    tgui::Gui gui{window};

    std::vector<paramsel> paramsex;


    auto label_filepan = tgui::Label::create();
    gui.add(label_filepan);
    label_filepan->setSize(500,24);
    label_filepan->setPosition(100,20);
    label_filepan->getRenderer()->setTextColor(sf::Color(255,255,255,255));

    auto label_colpan = tgui::Label::create();
    gui.add(label_colpan);
    label_colpan->setSize(100,24);
    label_colpan->setPosition(500,20);
    label_colpan->getRenderer()->setTextColor(sf::Color(255,255,255,255));

    auto label_rowpan = tgui::Label::create();
    gui.add(label_rowpan);
    label_rowpan->setSize(100,24);
    label_rowpan->setPosition(600,20);
    label_rowpan->getRenderer()->setTextColor(sf::Color(255,255,255,255));



    auto button_relfile = tgui::Button::create();
    gui.add(button_relfile);
    button_relfile->setSize(100,24);
    button_relfile->setPosition(210,50);
    button_relfile->setText("Reload File");


    auto cbox_params = tgui::ComboBox::create();
    gui.add(cbox_params);
    cbox_params->addItem("0");
    cbox_params->addItem("1");
    cbox_params->addItem("2");
    cbox_params->addItem("3");
    cbox_params->addItem("4");
    cbox_params->addItem("5");
    cbox_params->addItem("6");
    cbox_params->addItem("7");
    cbox_params->addItem("8");
    cbox_params->addItem("9");
    cbox_params->setSelectedItemByIndex(0); // Selects "Second"

    std::vector<tgui::ComboBox::Ptr> cbox_paramselz;

    std::vector<tgui::Label::Ptr> label_paramselz;


    tgui::Group::Ptr group_paramz=tgui::Group::create();
    gui.add(group_paramz);
    group_paramz->setSize(800,200);
    group_paramz->setPosition(430,0);

    cbox_params->setSize(100,24);
    cbox_params->setPosition(320,50);
    cbox_params->onItemSelect([&](int index){
    sett::paramsc=index;

    cbox_paramselz={};

    label_paramselz={};
    group_paramz->removeAllWidgets();
    for(int ix=0;ix<index;ix++){
        cbox_paramselz.push_back(tgui::ComboBox::create());
        label_paramselz.push_back(tgui::Label::create());
        cbox_paramselz[ix]->setSize(100,24);
        cbox_paramselz[ix]->setPosition((ix%5)*110,50+int((ix / 5))*60);
        for(int it=0;it<xdata::colz;it++){
            cbox_paramselz[ix]->addItem(std::to_string(it));
        }
        label_paramselz[ix]->setSize(100,24);
        label_paramselz[ix]->setPosition((ix%5)*110,30+int((ix / 5))*60);
        label_paramselz[ix]->getRenderer()->setTextColor(sf::Color(255,255,255,255));
        label_paramselz[ix]->setText("Parameter "+std::to_string(ix+1)+":");

        group_paramz->add(cbox_paramselz[ix]);

        group_paramz->add(label_paramselz[ix]);
        cbox_paramselz[ix]->onItemSelect([&,ix](int index2){
        sett::parco[ix] = index2;

        });


    }
    });

    auto label_res=tgui::Label::create();
    auto cbox_res=tgui::ComboBox::create();
    cbox_res->setSize(100,24);
    cbox_res->setPosition(870,110);
    cbox_res->addItem("0");
    cbox_res->addItem("1");
    cbox_res->addItem("2");
    cbox_res->addItem("3");
    cbox_res->addItem("4");
    label_res->setSize(100,24);
    label_res->setPosition(870,90);
    label_res->getRenderer()->setTextColor(sf::Color(255,255,255,255));
    label_res->setText("Results:");
    gui.add(label_res);
    gui.add(cbox_res);
    cbox_res->onItemSelect([&](int index){
                           sett::resco=index;
                           });





    auto label_fun = tgui::Label::create();
    gui.add(label_fun);
    label_fun->setSize(100,24);
    label_fun->setPosition(100,190);
    label_fun->getRenderer()->setTextColor(sf::Color(255,255,255,255));
    label_fun->setText("Functions:");


    auto label_var = tgui::Label::create();
    gui.add(label_var);
    label_var->setSize(100,24);
    label_var->setPosition(100,440);
    label_var->getRenderer()->setTextColor(sf::Color(255,255,255,255));
    label_var->setText("Variables:");



    auto label_exreg = tgui::Label::create();
    gui.add(label_exreg);
    label_exreg->setSize(100,24);
    label_exreg->setPosition(100,90);
    label_exreg->getRenderer()->setTextColor(sf::Color(255,255,255,255));
    label_exreg->setText("Extra Register:");

    auto label_boreg = tgui::Label::create();
    gui.add(label_boreg);
    label_boreg->setSize(100,24);
    label_boreg->setPosition(100,140);
    label_boreg->getRenderer()->setTextColor(sf::Color(255,255,255,255));
    label_boreg->setText("Bool Register:");


    auto label_persiv = tgui::Label::create();
    gui.add(label_persiv);
    label_persiv->setSize(100,24);
    label_persiv->setPosition(210,140);
    label_persiv->getRenderer()->setTextColor(sf::Color(255,255,255,255));
    label_persiv->setText("Persistent:");


    auto label_breakq = tgui::Label::create();
    gui.add(label_breakq);
    label_breakq->setSize(100,24);
    label_breakq->setPosition(320,140);
    label_breakq->getRenderer()->setTextColor(sf::Color(255,255,255,255));
    label_breakq->setText("Break Mode Q:");


    auto label_breaka = tgui::Label::create();
    gui.add(label_breaka);
    label_breaka->setSize(100,24);
    label_breaka->setPosition(430,140);
    label_breaka->getRenderer()->setTextColor(sf::Color(255,255,255,255));
    label_breaka->setText("Break Mode A:");


    auto list_data =tgui::ListView::create();
    gui.add(list_data);
    list_data->setPosition(100,510);
    list_data->setSize(880,270);


    auto button_selfile = tgui::Button::create();
    gui.add(button_selfile);
    button_selfile->setSize(100,24);
    button_selfile->setPosition(100,50);
    button_selfile->setText("Select File");
    button_selfile->onClick([&,&label_filepan]{
                            xdata::filepo=filesel::sel();
                            label_filepan->setText(xdata::filepo);
                            fileload::load(xdata::filepo);
                            fileload::swaprc();
                            if (sett::swaprcx){
                                xdata::colz=xdata::sfdata[0].size();
                                xdata::rowz=xdata::sfdata.size();
                            }else{
                                xdata::colz=xdata::fdata[0].size();
                                xdata::rowz=xdata::fdata.size();
                            }
                            label_colpan->setText("Columns: "+std::to_string(xdata::colz));
                            label_rowpan->setText("Rows: "+std::to_string(xdata::rowz));
                            for(int ix=0;ix<cbox_paramselz.size();ix++){
                                    cbox_paramselz[ix]->removeAllItems();
                                }
                            cbox_res->removeAllItems();

                            for(int it=0;it<xdata::colz;it++){
                                for(int ix=0;ix<cbox_paramselz.size();ix++){
                                    cbox_paramselz[ix]->addItem(std::to_string(it));
                                }
                                cbox_res->addItem(std::to_string(it));
                            }
                            list_data->removeAllItems();
                            list_data->removeAllColumns();
                            list_data->addColumn("Row");
                            for(int ix=0;ix<xdata::colz;ix++){
                                    list_data->addColumn("Column "+std::to_string(ix));
                            }
                            if (sett::swaprcx){
                            for(int ix=0;ix<xdata::rowz;ix++){
                                    std::vector<tgui::String> rowvec={std::to_string(ix)};
                                    for(int jx=0;jx<xdata::colz;jx++){
                                        rowvec.push_back(std::to_string(xdata::sfdata[ix][jx]));
                                    }
                                    list_data->addItem(rowvec);
                                    }
                                    }else{
                            for(int ix=0;ix<xdata::rowz;ix++){
                                    std::vector<tgui::String> rowvec={std::to_string(ix)};
                                    for(int jx=0;jx<xdata::colz;jx++){
                                        rowvec.push_back(std::to_string(xdata::fdata[ix][jx]));
                                    }
                                    list_data->addItem(rowvec);
                                    }}


                            });

    auto cbox_exreg = tgui::ComboBox::create();
    gui.add(cbox_exreg);
    cbox_exreg->addItem("0");
    cbox_exreg->addItem("1");
    cbox_exreg->addItem("2");
    cbox_exreg->addItem("3");
    cbox_exreg->addItem("4");
    cbox_exreg->setSelectedItemByIndex(0); // Selects "Second"

    cbox_exreg->setSize(100,24);
    cbox_exreg->setPosition(100,110);
    cbox_exreg->onItemSelect([](int index){
        sett::exregc=index;
    });

    auto cbox_boreg = tgui::ComboBox::create();
    gui.add(cbox_boreg);
    cbox_boreg->addItem("1");
    cbox_boreg->addItem("2");
    cbox_boreg->addItem("3");
    cbox_boreg->addItem("4");
    cbox_boreg->setSelectedItemByIndex(0); // Selects "Second"

    cbox_boreg->setSize(100,24);
    cbox_boreg->setPosition(100,165);
    cbox_boreg->onItemSelect([&](int index){
        sett::boregc=index+1;
    });


    auto label_lrlvl = tgui::Label::create();
    gui.add(label_lrlvl);
    label_lrlvl->setSize(100,24);
    label_lrlvl->setPosition(210,90);
    label_lrlvl->getRenderer()->setTextColor(sf::Color(255,255,255,255));
    label_lrlvl->setText("Recursion:");



    auto cbox_lrlvl = tgui::ComboBox::create();
    gui.add(cbox_lrlvl);
    cbox_lrlvl->addItem("0");
    cbox_lrlvl->addItem("1");
    cbox_lrlvl->addItem("2");
    cbox_lrlvl->addItem("3");
    cbox_lrlvl->addItem("4");
    cbox_lrlvl->addItem("5");
    cbox_lrlvl->setSelectedItemByIndex(0); // Selects "Second"

    cbox_lrlvl->setSize(100,24);
    cbox_lrlvl->setPosition(210,110);
    cbox_lrlvl->onItemSelect([](int index){
    sett::lrlvl=index;
    });


    auto ebox_breakq = tgui::EditBox::create();
    gui.add(ebox_breakq);
    ebox_breakq->setText("0");
    ebox_breakq->setSize(100,24);
    ebox_breakq->setPosition(320,165);
    ebox_breakq->onTextChange([](const tgui::String& text){
        sett::breakmodeq=std::stod((std::string)text);
    });

    auto ebox_breaka = tgui::EditBox::create();
    gui.add(ebox_breaka);
    ebox_breaka->setText("0.001");
    ebox_breaka->setSize(100,24);
    ebox_breaka->setPosition(430,165);
    ebox_breaka->onTextChange([](const tgui::String& text){
        sett::breakmodea=std::stod((std::string)text);
    });


    auto cbox_persiv = tgui::ComboBox::create();
    gui.add(cbox_persiv);
    cbox_persiv->addItem("0");
    cbox_persiv->addItem("1");
    cbox_persiv->addItem("2");
    cbox_persiv->addItem("3");
    cbox_persiv->addItem("4");
    cbox_persiv->addItem("5");
    cbox_persiv->setSelectedItemByIndex(0); // Selects "Second"

    cbox_persiv->setSize(100,24);
    cbox_persiv->setPosition(210,165);
    cbox_persiv->onItemSelect([&](int index){
        sett::persivc=index;
    });

    auto label_int = tgui::Label::create();
    gui.add(label_int);
    label_int->setSize(100,24);
    label_int->setPosition(320,90);
    label_int->getRenderer()->setTextColor(sf::Color(255,255,255,255));
    label_int->setText("Integer:");



    auto cbox_int = tgui::ComboBox::create();
    gui.add(cbox_int);
    cbox_int->addItem("None");
    for(int i=0;i<26;i++){
            cbox_int->addItem(std::to_string(i));
    }
    cbox_int->setSelectedItemByIndex(0); // Selects "Second"

    cbox_int->setSize(100,24);
    cbox_int->setPosition(320,110);
    cbox_int->onItemSelect([](int index){
    sett::intec=index;
    });

    auto button_swap = tgui::Button::create();
    gui.add(button_swap);
    button_swap->setSize(100,24);
    button_swap->setPosition(800,800);
    button_swap->setText("Swap R/C");
    button_swap->getRenderer()->setBackgroundColor(sf::Color(255,0,0,255));
            button_swap->getRenderer()->setBackgroundColorHover(sf::Color(255,64,64,255));
    button_swap->onClick([&]{
        sett::swaprcx=!sett::swaprcx;
        if(sett::swaprcx){
                button_swap->getRenderer()->setBackgroundColor(sf::Color(0,255,0,255));
                button_swap->getRenderer()->setBackgroundColorHover(sf::Color(64,255,64,255));}
        else{
            button_swap->getRenderer()->setBackgroundColor(sf::Color(255,0,0,255));
            button_swap->getRenderer()->setBackgroundColorHover(sf::Color(255,64,64,255));}
    }
                             );





//    std::vector<exreg *> exregz;
//    for(int fb;fb<lists::reglist.size();fb++)
//    {exregz.push_back(new exreg(&gui,fb));}

    std::vector<funbool *> funboolz;
    for(int fb;fb<sett::ifun.size();fb++)
    {funboolz.push_back(new funbool(&gui,fb));}

    std::vector<varbool *> varboolz;
    for(int fb;fb<sett::ivar.size();fb++)
    {varboolz.push_back(new varbool(&gui,fb));}

    while (window.isOpen())
{
//    for(int fb=0;fb<exregz.size();fb++){
//                    if (a==0){
//        //exregz[fb]->scol()
//        ;}
//    }
    for(int fb=0;fb<funboolz.size();fb++){
        funboolz[fb]->scol();
    }
    for(int fb=0;fb<varboolz.size();fb++){
        varboolz[fb]->scol();
    }
    sf::Event event;
    while (window.pollEvent(event))
    {
        gui.handleEvent(event);

        if (event.type == sf::Event::Closed)
            window.close();
    }


    window.clear();

    gui.draw();

    window.display();
}

	return;
            }
