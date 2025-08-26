#ifndef FETACHEESE_H
#define FETACHEESE_H
#include "Topping.h"
#include <string>

class FetaCheese : public Topping
{
public:
    FetaCheese() : Topping() {}
    FetaCheese(double price, std::string name) : Topping(price, name) {}
    ~FetaCheese() = default;
};
#endif