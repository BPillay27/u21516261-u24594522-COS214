#include "ExportCanvas.h"
#include "Canvas.h"
#include <iostream>

ExportCanvas::ExportCanvas(Canvas *exportDis)
{
    if (exportDis == nullptr)
    {
        return;
    }
    canvas = exportDis;
}

ExportCanvas::~ExportCanvas()
{
    if (canvas != nullptr)
    {
        delete canvas;
        canvas = nullptr;
    }
}

void ExportCanvas::exportToFile()
{
    this->prepareCanvas();
    this->renderCanvas();
    this->saveToFile();
    canvas = nullptr; // canvas will take care of itself, meaning memory wise.
}

void ExportCanvas::prepareCanvas()
{
    std::cout << "Preparing canvas for export..." << std::endl;
}

void ExportCanvas::renderCanvas()
{
    std::cout << "Rendering canvas..." << std::endl;
}
