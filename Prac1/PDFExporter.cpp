#include "PDFExporter.h"
#include <iostream>

PDFExporter::PDFExporter(Canvas *exportDis) : ExportCanvas(exportDis)
{
}

void PDFExporter::saveToFile()
{
    std::cout << "Saving the canvas to PDF file" << std::endl;
}