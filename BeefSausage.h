#ifndef BEEFSAUSAGE_H
#define BEEFSAUSAGE_H

#include "Topping.h"
#include <string>

class BeefSausage : public Topping
{
public:
    BeefSausage() : Topping() {}
    BeefSausage(double price, std::string name) : Topping(price, name) {}
    ~BeefSausage() = default;
};

#endif