#ifndef TOMATOSAUCE_H
#define TOMATOSAUCE_H
#include "Topping.h"
#include <string>

class TomatoSauce : public Topping
{
public:
    TomatoSauce():Topping(5.00,"Tomato Sauce") {};
    ~TomatoSauce() = default;
};
#endif