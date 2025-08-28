#ifndef OLIVES_H
#define OLIVES_H
#include "Topping.h"
#include <string>

class Olives : public Topping
{
public:
    Olives() : Topping(15.00,"Olives"){};
    ~Olives() = default;
};
#endif