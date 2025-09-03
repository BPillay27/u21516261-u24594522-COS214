#ifndef MEMENTO_H
#define MEMENTO_H

#include "Shape.h"

class Shape;

class Memento
{
    friend class Canvas; // Allow Canvas to access private members
private:
    Shape *shapes;
    Shape *getShapes();

public:
    Memento(Shape *elements);
    ~Memento();
};

#endif