#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

#include <string>

class PizzaComponent
{
    friend class Topping;
    friend class ToppingGroup;
  public:
    PizzaComponent(double price,std::string name);
    virtual ~PizzaComponent();
    PizzaComponent(const PizzaComponent &old);
    virtual std::string getName()=0;
    virtual double getPrice()=0;
    virtual PizzaComponent* clone()=0;
private:
    double price;
    std::string name;
};

#endif
