#ifndef BEEFSAUSAGE_H
#define BEEFSAUSAGE_H

#include "Topping.h"
#include <string>

class BeefSausage : public Topping
{
public:

    BeefSausage() : Topping(25.00, "Beef Sausage") {};
    ~BeefSausage() = default;
};

#endif

