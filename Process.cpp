#include "Process.h"
#include "Order.h"

Process::Process(Order *order)
{
    this->order=order;
}

Process::~Process()
{
    //do nothing. Process belongs to order. should not delete its owner?
}

