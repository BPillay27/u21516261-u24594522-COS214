#ifndef FAMILYDISCOUNT_H
#define FAMILYDISCOUNT_H

#include "DiscountStrategy.h"

class FamilyDiscount : public DiscountStrategy
{
public:
    FamilyDiscount(double _price);
    double applyDiscount();
    ~FamilyDiscount()=default;
};

#endif
