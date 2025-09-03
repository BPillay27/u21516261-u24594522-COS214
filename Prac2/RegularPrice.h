#ifndef REGULARPIRCE_H
#define REGULARPIRCE_H

#include "DiscountStrategy.h"

class RegularPrice : public DiscountStrategy{
    public:
    RegularPrice(double _price);
    double applyDiscount();
    ~RegularPrice()=default;
};

#endif
