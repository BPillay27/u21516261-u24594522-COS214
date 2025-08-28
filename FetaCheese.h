#ifndef FETACHEESE_H
#define FETACHEESE_H
#include "Topping.h"
#include <string>

class FetaCheese : public Topping
{
public:
    FetaCheese() : Topping(18.00,"Feta Cheese") {};
    ~FetaCheese() = default;
};
#endif