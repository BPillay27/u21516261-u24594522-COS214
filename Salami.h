#ifndef SALAMI_H
#define SALAMI_H
#include "Topping.h"
#include <string>

class Salami : public Topping
{
public:
    Salami() : Topping(22.00, "Salami") {};
    ~Salami() = default;
};
#endif