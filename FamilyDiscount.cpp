#include "FamilyDiscount.h"

FamilyDiscount::FamilyDiscount(double _price) : DiscountStrategy(_price)
{
}

double FamilyDiscount::applyDiscount()
{
    return getPrice() * 0.85;
}