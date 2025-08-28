#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

#include <string>

class PizzaComponent
{
    friend class Topping;
    friend class ToppingGroup;
public:
    virtual std::string getName() = 0;
    virtual double getPrice() = 0;
    PizzaComponent(double price, std::string name);
    virtual ~PizzaComponent();

private:
    double price;
    std::string name;
};

#endif