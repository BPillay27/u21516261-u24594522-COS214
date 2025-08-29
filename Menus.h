#ifndef MENUS_H
#define MENUS_H

#include "Observer.h"
#include "Pizza.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm> 

//class Observer;

class Menus{
    private:
        std::vector<Pizza*> pizzas;
    protected:
        std::vector<Observer*> observers;
    public:
        Menus();
        virtual ~Menus();
        void addObserver(Observer* observer);//attach
        void removeObserver(Observer* observer);//detach
        void addPizza(Pizza* pizza);
        void removePizza(Pizza* pizza);
        virtual void notifyObservers(std::string message)=0;
        Pizza* MenuIndex(int index);
};

#endif