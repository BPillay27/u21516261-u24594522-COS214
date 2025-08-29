#ifndef WEDSITE_H
#define WEDSITE_H

#include "Observer.h"
#include <iostream>

class Website:public Observer {

    public:
        Website();
        void update(std::string message);
        ~Website();
};

#endif