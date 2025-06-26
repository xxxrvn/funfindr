#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "clickable.h"

class button :  sf::Drawable, clickable
{
    public:
        button();
        virtual ~button();

    protected:

    private:
};

#endif // BUTTON_H
