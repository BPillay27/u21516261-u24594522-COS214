#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

#include <string>

class PizzaComponent
{
public:
    virtual std::string getName() = 0;
    virtual double getPrice() = 0;
    PizzaComponent(double price, std::string name);
    PizzaComponent() {}
    virtual ~PizzaComponent()=default;

protected:
    std::string getBaseName();
    double getBasePrice();

private:
    double price;
    std::string name;
};

#endif