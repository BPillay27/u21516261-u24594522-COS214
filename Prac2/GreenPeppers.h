#ifndef GREENPEPPERS_H
#define GREENPEPPERS_H
#include "Topping.h"
#include <string>

class GreenPeppers : public Topping
{
public:
    GreenPeppers() : Topping(10.00, "Green Peppers") {};
    ~GreenPeppers() = default;
};
#endif