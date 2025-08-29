#ifndef MUSHROOMS_H
#define MUSHROOMS_H
#include "Topping.h"
#include <string>

class Mushrooms : public Topping
{
public:
    Mushrooms() : Topping(12.00,"Mushrooms") {};
    ~Mushrooms() = default;
};
#endif