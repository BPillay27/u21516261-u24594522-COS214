#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H

#include "ShapeFactory.h"
#include "Rectangle.h"

class RectangleFactory : public ShapeFactory
{
public:
    RectangleFactory() {}
    ~RectangleFactory() {}
    Shape *createShape();
    void toString();
};

#endif