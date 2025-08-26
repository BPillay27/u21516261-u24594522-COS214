#ifndef PEPPERONI_H
#define PEPPERONI_H
#include "Topping.h"
#include <string>

class Pepperoni : public Topping
{
public:
    Pepperoni() : Topping() {}
    Pepperoni(double price, std::string name) : Topping(price, name) {}
    ~Pepperoni() = default;
};
#endif