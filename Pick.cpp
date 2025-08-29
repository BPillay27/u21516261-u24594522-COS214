#include "Pick.h"

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