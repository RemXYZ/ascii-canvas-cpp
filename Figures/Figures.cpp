#include "../ASCIICanvas.h"
#ifndef FIGURE_H
#define FIGURE_H

class ASCIICanvas; // Deklaracja przed forward declaration

class Figure {
public:
    virtual ~Figure() = default;
    virtual void draw(ASCIICanvas &c) = 0;
    virtual void setSymbol(char symbol) = 0;

protected:
    char symbol;
};

#endif




