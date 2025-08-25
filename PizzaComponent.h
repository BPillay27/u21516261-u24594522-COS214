#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

#include <string>

class PizzaComponent
{
public:
    virtual std::string getName();
    virtual double getPrice();
    PizzaComponent(double price, std::string name);
    PizzaComponent(){}
    virtual ~PizzaComponent();
private:
    double price;
    std::string name;
};

#endif