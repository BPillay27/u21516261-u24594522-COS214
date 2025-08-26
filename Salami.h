#ifndef SALAMI_H
#define SALAMI_H
#include "Topping.h"
#include <string>

class Salami : public Topping
{
public:
    Salami() : Topping() {}
    Salami(double price, std::string name) : Topping(price, name) {}
    ~Salami() = default;
};
#endif