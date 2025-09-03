#ifndef PICK_H
#define PICK_H

#include "Process.h"
class Order;

class Pick: public Process{
    public:
    Pick(Order* order);
    ~Pick();
    void proceed();
};

#endif