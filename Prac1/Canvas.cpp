#include "Canvas.h"

Canvas::Canvas()
{
    caretaker = new Caretaker();
}

Canvas::~Canvas()
{
    if (caretaker != nullptr)
    {
        delete caretaker;
    }
    clearCanvas();
}

Memento *Canvas::captureCurrent()
{
    if (shapes == nullptr)
    {
        return nullptr;
    }
    return new Memento(shapes);
}
 
void Canvas::undoAction()
{
    if(shapes==nullptr){
        return;
    }
    Memento *j = new Memento(shapes->clone()); // memory leak. Cant delete this?
    j = caretaker->undo(j);
}

void Canvas::redoAction()
{
    if(shapes==nullptr){
        return;
    }
    Memento *j = new Memento(shapes->clone());
    j = caretaker->redo(j);
}

void Canvas::continueAction()
{
    caretaker->continueAction();
}

void Canvas::clearCanvas()
{
    if (shapes != nullptr)
    {
        delete shapes;
    }
    shapes = nullptr;
}

void Canvas::addToCanvas(Shape *shape)
{
    if (shape == nullptr)
        return;
    if (shapes == nullptr)
    {
        shapes = shape->clone();
    }
    else
    {
        caretaker->add(captureCurrent());
        // captures the current state of the canvas before adding a new shape
        clearCanvas();
        shapes = shape->clone();
    }
}

void Canvas::removeFromCanvas()
{
    if (shapes == nullptr)
    {
        return;
        // Assuming shapes is a single Shape pointer, not a collection
    }
    else
    {
        caretaker->continueAction();
        clearCanvas();
    }
}

void Canvas::PNGCanvas()
{
    PNGExporter canvasExporter = PNGExporter(this);
    canvasExporter.exportToFile();
}

void Canvas::PDFCanvas()
{
    PDFExporter canvasExporter = PDFExporter(this);
    canvasExporter.exportToFile();
}

void Canvas::addShape(std::string shape)
{
    if (shape == "rectangle" || shape == "Rectangle")
    {
        RectangleFactory rectangleFactory = RectangleFactory();
        Shape *newShape = rectangleFactory.createShape();
        addToCanvas(newShape);
    }
    else if (shape == "Textbox" || shape == "textbox")
    {
        TextboxFactory textboxFactory = TextboxFactory();
        Shape *newShape = textboxFactory.createShape();
        addToCanvas(newShape);
    }
    else if (shape == "square" || shape == "Square")
    {
        SquareFactory squareFactory = SquareFactory();
        Shape *newShape = squareFactory.createShape();
        addToCanvas(newShape);
    }
    else
    {
        std::cout << "The shapes doesn't exist, try again" << std::endl;
    }
}

void Canvas::changeLength(int length)
{
    if (shapes != nullptr)
    {
        shapes->changeLength(length);
    }
}

void Canvas::changeWidth(int width)
{
    if (shapes != nullptr)
    {
        shapes->changeWidth(width);
    }
}

void Canvas::changeColour(std::string colour)
{
    if (shapes != nullptr)
    {
        shapes->changeColour(colour);
    }
}

void Canvas::changePosition(int x, int y)
{
    if (shapes != nullptr)
    {
        shapes->changePosition(x, y);
    }
}

void Canvas::contains()
{
    if (shapes != nullptr)
    {
        shapes->toString();
    }
    else
    {
        std::cout << "There is no shape on the canvas yet, please add one before calling me again. Kind regards/n -Contains()" << std::endl;
    }
}
