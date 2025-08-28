#ifndef TOPPINGGROUP_H
#define TOPPINGGROUP_H

#include "PizzaComponent.h"
#include <list>
#include <string>

class ToppingGroup : public PizzaComponent
{
public:
    ToppingGroup(std::string name);
    ~ToppingGroup();
    void add(PizzaComponent *component);
    void remove(PizzaComponent *component);
    std::string getName();
    double getPrice();

private:
    std::list<PizzaComponent*> toppings;
};

#endif