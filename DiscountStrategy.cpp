#include "DiscountStrategy.h"

DiscountStrategy::DiscountStrategy(double _price)
{
    price=_price;
}

double DiscountStrategy::getPrice(){
    return price;
}