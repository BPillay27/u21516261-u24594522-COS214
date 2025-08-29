#ifndef EXTRACHEESE_H
#define EXTRACHEESE_H

#include "PizzaDecorator.h"
#include "Pizza.h"

class ExtraCheese : public PizzaDecorator
{
public:
    ExtraCheese(Pizza* pizza);
    ~ExtraCheese();
    std::string getName();
    double getPrice();
    Pizza* clone();
    ExtraCheese(const ExtraCheese &old);
};

#endif