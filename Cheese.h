#ifndef CHEESE_H
#define CHEESE_H
#include "Topping.h"
#include <string>

class Cheese : public Topping
{
public:
    Cheese() : Topping(15.00, "Cheese") {};
    ~Cheese() = default;
};
#endif