#ifndef SPECIALMENU_H
#define SPECIALMENU_H

#include "Menus.h"


class SpecialMenu :public Menus{
    public:
        SpecialMenu();
        ~SpecialMenu();
        void notifyObservers(std::string message);

};

#endif