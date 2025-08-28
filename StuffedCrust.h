#ifndef STUFFEDCRUST_H
#define STUFFEDCRUST_H

#include "PizzaDecorator.h"
#include "Pizza.h"

class StuffedCrust : public PizzaDecorator
{
public:
    StuffedCrust(Pizza *pizza);
    ~StuffedCrust();
    std::string getName() { return "Stuffed Crust"; }
    double getPrice() { return 20; }
};

#endif
