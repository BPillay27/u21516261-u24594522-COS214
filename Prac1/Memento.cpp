#include "Memento.h"

Memento::Memento(Shape *elements)
{
    if (elements == nullptr)
    {
        return;
    }
    else
    {
        shapes = elements->clone();
    }
}

Memento::~Memento()
{
    if (shapes != nullptr)
    {
        delete shapes;
    }
}

Shape *Memento::getShapes()
{
    return shapes;
}