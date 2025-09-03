#include "Pick.h"
#include "Order.h"
#include "Pay.h"

Pick::Pick(Order *order) : Process(order)
{
}

Pick::~Pick()
{
}

void Pick::proceed()
{
    std::cout<<"Please pick your pizzas\n";
    Process* temp=new Pay(order);
    order->setState(temp);
}

