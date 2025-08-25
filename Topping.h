#ifndef TOPPING_H
#define TOPPING_H

#include "PizzaComponent.h"
#include <string>

class Topping : public PizzaComponent
{
public:
    Topping();
    Topping(double price, std::string name);
    std::string getName();
    double getPrice();
};
#endif