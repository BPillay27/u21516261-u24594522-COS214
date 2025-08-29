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
    Process* temp=new Pay(order);
    order->setState(temp);
}