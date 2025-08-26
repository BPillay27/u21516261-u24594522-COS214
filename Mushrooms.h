#ifndef MUSHROOMS_H
#define MUSHROOMS_H
#include "Topping.h"
#include <string>

class Mushrooms : public Topping
{
public:
    Mushrooms() : Topping() {}
    Mushrooms(double price, std::string name) : Topping(price, name) {}
    ~Mushrooms() = default;
};
#endif