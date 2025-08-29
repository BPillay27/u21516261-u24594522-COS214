#ifndef PREPARE_H
#define PREPARE_H

#include "Process.h"
#include "Order.h"
#include "Finished.h"

class Prepare : public Process
{
    public:
    Prepare(Order* order);
    void proceed();
    ~Prepare(){}
};

#endif
