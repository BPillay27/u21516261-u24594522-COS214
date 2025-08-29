#ifndef PIZZAMENU_H
#define PIZZAMENU_H

#include "Menus.h"

class PizzaMenu :public Menus{
    public:
        PizzaMenu();
        ~PizzaMenu();
        void notifyObservers(std::string message);

};

#endif