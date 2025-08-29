#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

class DiscountStrategy
{
public:
    DiscountStrategy(double _price);
    virtual double applyDiscount() = 0;
    double getPrice();
    virtual ~DiscountStrategy()=default;
private:
    double price;
};

#endif
