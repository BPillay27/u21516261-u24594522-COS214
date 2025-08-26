#ifndef CHEESE_H
#define CHEESE_H
#include "Topping.h"
#include <string>

class Cheese : public Topping
{
public:
    Cheese() : Topping() {}
    Cheese(double price, std::string name) : Topping(price, name) {}
    ~Cheese() = default;
};
#endif