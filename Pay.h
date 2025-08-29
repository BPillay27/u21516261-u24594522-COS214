#ifndef PAY_H
#define PAY_H

#include "Process.h"
#include "Order.h"
#include "DiscountStrategy.h"
#include "Prepare.h"
#include "BulkDiscount.h"
#include "FamilyDiscount.h"
#include "RegularPrice.h"

class Pay : public Process{
    public:
    Pay(Order* order);
    void proceed();
    double applyDiscount(double total);
    void declined();
    void approved();
    void total();
    ~Pay();

    private:
    DiscountStrategy* discount;
};

#endif
