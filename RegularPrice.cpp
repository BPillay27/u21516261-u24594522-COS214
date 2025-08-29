#include "RegularPrice.h"

RegularPrice::RegularPrice(double _price) : DiscountStrategy(_price)
{
}

double RegularPrice::applyDiscount()
{
    return getPrice();
}