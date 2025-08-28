#ifndef PIZZADECORATOR_H
#define PIZZADECORATOR_H

#include "Pizza.h"
#include <string>



class PizzaDecorator : public Pizza
{
    friend class ExtraCheese;
    friend class StuffedCrust;
public:
    PizzaDecorator(Pizza* pizza);
    virtual ~PizzaDecorator();
    virtual std::string getName() = 0;
    virtual double getPrice() = 0;
    void add(Pizza extra);

private:
    Pizza *pizza;
};

#endif