#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include "Memento.h"
#include "Caretaker.h"
#include "PNGExporter.h"
#include "SquareFactory.h"
#include "TextboxFactory.h"
#include "RectangleFactory.h"
#include "PDFExporter.h"
#include "Shape.h"

class Shape;     // Letting it know that Shape exists
class Caretaker; // Letting it know that Caretaker exists
class Memento;   // Letting it know that Memento exists

class Canvas
{
private:
    Shape *shapes;
    Caretaker *caretaker;

public:
    Canvas();
    ~Canvas();
    Memento *captureCurrent();
    void undoAction();
    void redoAction();
    void continueAction();
    void addToCanvas(Shape *shape);
    void removeFromCanvas();
    void clearCanvas();
    void PNGCanvas();
    void PDFCanvas();
    void addShape(std::string shape);
    void changeLength(int length);
    void changeWidth(int width);
    void changeColour(std::string colour);
    void changePosition(int x, int y);
    void contains();
};

#endif
