#ifndef TOPPING_H
#define TOPPING_H

#include "PizzaComponent.h"
#include <string>

class Topping : public PizzaComponent
{
public:
    Topping(double price, std::string name);
    ~Topping();
    std::string getName();
    double getPrice();
    Topping(const Topping &old);
    PizzaComponent* clone();
};
#endif