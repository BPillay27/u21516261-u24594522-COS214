#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

#include <string>

class PizzaComponent
{
    friend class Topping;
public:
    virtual std::string getName() = 0;
    virtual double getPrice() = 0;
    PizzaComponent(double price, std::string name);
    PizzaComponent() {}
    virtual ~PizzaComponent()=default;
private:
    double price;
    std::string name;
};

#endif
