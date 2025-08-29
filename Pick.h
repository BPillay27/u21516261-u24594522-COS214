#ifndef PICK_H
#define PICK_H

#include "Process.h"
#include "Order.h"
#include "Pay.h"

class Pick: public Process{
    public:
    Pick(Order* order);
    ~Pick();
    void proceed();
};

#endif