#ifndef BULKDISCOUNT_H
#define BULKDISCOUNT_H

#include "DiscountStrategy.h"

class BulkDiscount : public DiscountStrategy
{
public:
    BulkDiscount(double _price);
    double applyDiscount();
    ~BulkDiscount();
};

#endif