#include "Pay.h"

Pay::Pay(Order *order) : Process(order)
{
}

void Pay::proceed()
{
    int decision = std::rand() % 2;
    decision == 0 ? approved() : declined();
}

double Pay::applyDiscount(double total)
{
    if(order->getCount()>=5){
        discount=new BulkDiscount(total);
    } else{
        int decision = std::rand() % 2;
        decision==0? discount=new RegularPrice(total) : discount=new FamilyDiscount(total);
    }
    
    return discount->applyDiscount();
}

void Pay::declined()
{
    Process *temp = new Pick(order);
    order->setState(temp);
}

void Pay::approved()
{
    Process* temp=new Prepare(order);
    order->setState(temp);
}

void Pay::total()
{
}

Pay::~Pay()
{
     if(discount!=nullptr) delete discount;
    discount=nullptr;
}
