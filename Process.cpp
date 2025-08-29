#include "Process.h"

Process::Process(Order *order)
{
    this->order=order;
}

Process::~Process()
{
    //do nothing. Process belongs to order. should not delete its owner?
}

double Process::getTotalPrice()
{
    return order->getTotalPrice();
}
