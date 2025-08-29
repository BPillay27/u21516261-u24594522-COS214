#include "DiscountStrategy.h"

DiscountStrategy::DiscountStrategy(double _price)
{
    total=_price;
}

double DiscountStrategy::getPrice(){
    return total;
}