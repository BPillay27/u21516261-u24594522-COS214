#include "PNGExporter.h"
#include <iostream>

PNGExporter::PNGExporter(Canvas *exportDis) : ExportCanvas(exportDis)
{
}

void PNGExporter::saveToFile()
{
    std::cout << "Saving the canvas to PNG file" << std::endl;
}