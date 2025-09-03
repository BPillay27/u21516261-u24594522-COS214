#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "Shape.h"
class Shape;

class ShapeFactory
{
protected:
    virtual Shape *createShape() = 0; // pure virtual function
    virtual void toString() = 0;      // pure virtual function

public:
    ShapeFactory() = default;
    virtual ~ShapeFactory() = default; // virtual destructor
};

#endif
