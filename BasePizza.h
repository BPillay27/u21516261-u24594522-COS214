#ifndef BASEPIZZA_H
#define BASEPIZZA_H

#include "PizzaComponent.h"
#include <string>
#include "Pizza.h"

class BasePizza : public Pizza
{
public:
    double getPrice();
    std::string getName();
    BasePizza(PizzaComponent *topping);
    ~BasePizza();
    BasePizza();

private:
    PizzaComponent *toppings;
};

#endif