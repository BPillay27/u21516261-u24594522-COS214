#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

class DiscountStrategy
{
public:
    DiscountStrategy(double _price);
    virtual double applyDiscount() = 0;
    virtual ~DiscountStrategy()=default;
protected:
    double getPrice();
private:
    double total;
};

#endif
