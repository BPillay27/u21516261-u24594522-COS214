#ifndef PDFExporter_H
#define PDFExporter_H

#include "ExportCanvas.h"
#include <iostream>

class PDFExporter : public ExportCanvas
{
private:
    void saveToFile();

public:
    PDFExporter(Canvas *exportDis);
};
#endif