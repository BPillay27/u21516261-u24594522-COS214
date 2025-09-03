#ifndef PAY_H
#define PAY_H

#include "Process.h"
class Order;
class DiscountStrategy;

class Pay : public Process{
    public:
    Pay(Order* order);
    void proceed();
    double applyDiscount();
    void declined();
    void approved();
    double total();
    ~Pay();

    private:
    DiscountStrategy* discount;
};

#endif
