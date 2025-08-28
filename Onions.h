#ifndef ONIONS_H
#define ONIONS_H
#include "Topping.h"
#include <string>

class Onions : public Topping
{
public:
    Onions() : Topping(8.00,"Onions") {};
    ~Onions() = default;
};
#endif