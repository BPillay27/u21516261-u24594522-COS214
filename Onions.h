#ifndef ONIONS_H
#define ONIONS_H
#include "Topping.h"
#include <string>

class Onions : public Topping
{
public:
    Onions() : Topping() {}
    Onions(double price, std::string name) : Topping(price, name) {}
    ~Onions() = default;
};
#endif