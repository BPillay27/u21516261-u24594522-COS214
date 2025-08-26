#ifndef TOMATOSAUCE_H
#define TOMATOSAUCE_H
#include "Topping.h"
#include <string>

class TomatoSauce : public Topping
{
public:
    TomatoSauce() : Topping() {}
    TomatoSauce(double price, std::string name) : Topping(price, name) {}
    ~TomatoSauce() = default;
};
#endif