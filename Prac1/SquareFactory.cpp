#include "SquareFactory.h"

Shape *SquareFactory::createShape()
{
    toString();
    return new Square();
}
void SquareFactory::toString()
{
    std::cout << "Square factory producing square." << std::endl;
}
