#ifndef DOUGH_H
#define DOUGH_H
#include "Topping.h"
#include <string>

class Dough : public Topping
{
public:
    Dough() : Topping(10.00,"Dough") {};
    ~Dough() = default;
};
#endif