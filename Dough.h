#ifndef DOUGH_H
#define DOUGH_H
#include "Topping.h"
#include <string>

class Dough : public Topping
{
public:
    Dough() : Topping() {}
    Dough(double price, std::string name) : Topping(price, name) {}
    ~Dough() = default;
};
#endif