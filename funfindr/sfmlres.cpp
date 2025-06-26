#include "sfmlres.h"

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
#include "tcalc.h"
#include <thread>
#include "rdata.h"
#include "data.h"
#include "gen.h"
#include "xdata.h"

#include <string>

    void sfmlres::start(){
    int a=0;
    sf::RenderWindow window{{1200, 900}, "TGUI example - SFML_GRAPHICS backend"};
    tgui::Gui gui{window};

    std::thread calcres (tcalc::calc);
    int gotres=0;
    auto restext=tgui::Label::create();
    gui.add(restext);

        restext->setSize(200,400);
        restext->setPosition(100,510);
        restext->getRenderer()->setTextColor(sf::Color(255,255,255,255));
    auto res_group=tgui::Group::create();
    gui.add(res_group);
    res_group->setSize(1000,500);

    auto label_tries=tgui::Label::create();
    gui.add(label_tries);
    label_tries->setSize(200,400);
    label_tries->setPosition(900,100);
    label_tries->getRenderer()->setTextColor(sf::Color(255,255,255,255));


    auto list_data =tgui::ListView::create();
    gui.add(list_data);
    list_data->setPosition(500,510);
    list_data->setSize(600,270);


    auto label_xcodecr=tgui::Label::create();
    gui.add(label_xcodecr);
    label_xcodecr->setSize(200,400);
    label_xcodecr->setPosition(900,20);
    label_xcodecr->getRenderer()->setTextColor(sf::Color(255,255,255,255));

    while (window.isOpen())
{
        label_xcodecr->setText(gen::sss.str());
        label_tries->setText(std::to_string(data::tries));
       if(rdata::resis.size()>gotres){

            gotres=rdata::resis.size();

            res_group->removeAllWidgets();
            for(int ix=0;ix<rdata::resis.size();ix++){

                auto resres=tgui::Group::create();
                resres->setSize(90,90);
                resres->setPosition((ix%10)*100,(int(ix/10)*100));
                res_group->add(resres);


                auto backres=tgui::Button::create();

                backres->setSize(90,90);
                backres->setPosition(0,0);
                backres->getRenderer()->setBackgroundColor(sf::Color(36,36,36,255));
                resres->add(backres);
                backres->onClick([&,ix]{
                    restext->setText(rdata::resis[ix]->funis.str());
                    list_data->removeAllItems();
                    list_data->removeAllColumns();
                    list_data->addColumn("Row");
                    for(int ex=0;ex<sett::paramsc;ex++){
                            list_data->addColumn("Parameter "+std::to_string(ex));
                    }
                    list_data->addColumn("Result   ");
                    list_data->addColumn("Result*  ");

                    list_data->addColumn("Error*   ");
                    for(int ex=0;ex<xdata::rowz;ex++){
                            std::vector<tgui::String> rowvec={std::to_string(ex)};
                            for(int jx=0;jx<sett::paramsc;jx++){
                               rowvec.push_back(std::to_string(xdata::pars[jx][ex]));
                            }
                            rowvec.push_back(std::to_string(xdata::results[ex]));
                            rowvec.push_back(std::to_string(rdata::resis[ix]->xres[ex]));
                            rowvec.push_back(std::to_string(rdata::resis[ix]->xerr[ex]));
                            list_data->addItem(rowvec);

                            }
                });

                auto labres=tgui::Label::create();
                labres->setText(std::to_string(rdata::resis[ix]->err));

                labres->setSize(100,24);
                labres->setPosition(0,0);
                labres->getRenderer()->setTextColor(sf::Color(255,255,255,255));
                resres->add(labres);

            };
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
