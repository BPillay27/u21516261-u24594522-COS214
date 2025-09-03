#ifndef PNGEXPORTER_H
#define PNGEXPORTER_H

#include "ExportCanvas.h"
#include <iostream>

class PNGExporter : public ExportCanvas
{
private:
    void saveToFile();

public:
    PNGExporter(Canvas *exportDis);
};

#endif