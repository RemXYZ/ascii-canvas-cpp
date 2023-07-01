#ifndef ASCIICANVAS_H
#define ASCIICANVAS_H

#include "Canvas.h"
// #include "Figure.h"
#include <iostream>
#include <memory>
#include <vector>
#include <fstream>

class ASCIICanvas : public Canvas {
public:
    ASCIICanvas(int widthArg, int heightArg, char bgSymbol, const std::string& output);
    ~ASCIICanvas() override;

    void setDimension(int widthArg, int heightArg) override;
    void draw() override;
    // void addFigure(std::shared_ptr<Figure> fig) override;
    int setPixel(int x, int y, char c);
    void setOutputFile(const std::string& output) {
        outputFile = output;
    }

private:
    std::ofstream outfile; 
    std::string outputFile;
    std::vector<std::vector<char>> canvas;
    void drawFrame();
};

#endif
