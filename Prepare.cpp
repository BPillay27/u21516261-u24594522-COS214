#include "Prepare.h"

Prepare::Prepare(Order *order) : Process(order)
{
}

void Prepare::proceed()
{
    Process *temp = new Finished(order);
    order->setState(temp);
}