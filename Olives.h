#ifndef OLIVES_H
#define OLIVES_H
#include "Topping.h"
#include <string>

class Olives : public Topping
{
public:
    Olives() : Topping() {}
    Olives(double price, std::string name) : Topping(price, name) {}
    ~Olives() = default;
};
#endif