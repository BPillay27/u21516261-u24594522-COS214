#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <iostream>

class Pizza
{
public:
    Pizza() = default; // default
    virtual ~Pizza() = default; //default
    virtual double getPrice() = 0; //pure virtual
    virtual std::string getName() = 0; // pure virtual
    void printPizza(); //implemented
};

#endif