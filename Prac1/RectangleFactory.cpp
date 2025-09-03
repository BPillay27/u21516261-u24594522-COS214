#include "RectangleFactory.h"

Shape *RectangleFactory::createShape()
{
    toString();
    return new Rectangle();
}

void RectangleFactory::toString()
{
    std::cout << "Square factory producing square." << std::endl;
}
