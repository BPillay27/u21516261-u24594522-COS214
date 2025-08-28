#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

#include <string>

class PizzaComponent
{
    
  public:
  friend class Topping;
    friend class ToppingGroup;
    virtual ~PizzaComponent();

private:
    double price;
    std::string name;
};

#endif