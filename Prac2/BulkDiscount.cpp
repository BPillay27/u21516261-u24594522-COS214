#include "BulkDiscount.h"

BulkDiscount::BulkDiscount(double _price) : DiscountStrategy(_price)
{
}

double BulkDiscount::applyDiscount()
{
    return getPrice() * 0.9;
}