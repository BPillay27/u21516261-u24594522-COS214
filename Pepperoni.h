#ifndef PEPPERONI_H
#define PEPPERONI_H
#include "Topping.h"
#include <string>

class Pepperoni : public Topping
{
public:
    Pepperoni() : Topping(20.00,"Pepperoni") {};
    ~Pepperoni() = default;
};
#endif