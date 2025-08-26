#ifndef GREENPEPPERS_H
#define GREENPEPPERS_H
#include "Topping.h"
#include <string>

class GreenPeppers : public Topping
{
public:
    GreenPeppers() : Topping() {}
    GreenPeppers(double price, std::string name) : Topping(price, name) {}
    ~GreenPeppers() = default;
};
#endif