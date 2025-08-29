#include "Pay.h"
#include "Pick.h"
#include "Process.h"
#include "Order.h"
#include "DiscountStrategy.h"
#include "Prepare.h"
#include "BulkDiscount.h"
#include "FamilyDiscount.h"
#include "RegularPrice.h"

Pay::Pay(Order* order) : Process(order)
{
    discount=nullptr;
}

void Pay::proceed()
{
    //std::cout<<" The decision"<<num1<<std::endl;
    int decision = std::rand() % 4;
    //std::cout<<" The decision"<<num2<<std::endl;
    if(decision==1){
        std::cout<<"The payment was declined maybe your balance is to low"<<std::endl;
        std::cout<<"The total was: "<<applyDiscount()<<std::endl;
        declined();
    }else{
        std::cout<<"The payment was approved"<<std::endl;
        std::cout<<"The total was: R"<<applyDiscount()<<std::endl;
        approved();
    }
}

double Pay::applyDiscount()
{
    double total=this->total();
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

double Pay::total()
{
    return order->getTotalPrice();
}

Pay::~Pay()
{
     if(discount!=nullptr) delete discount;
    discount=nullptr;
}
