#include "Canvas.h"
#include "ASCIICanvas.h"
// #include "Figures/Figures.h"


void clearScreen();
using namespace std;

ASCIICanvas::ASCIICanvas(int widthArg, int heightArg, char bgSymbolArg) {
    this->bgSymbol = bgSymbolArg;
    this->width = widthArg;
    this->height = heightArg;
    this->canvas.resize(height, std::vector<char>(width, bgSymbolArg));
}

void ASCIICanvas::draw() {
    
    clearScreen();
    drawFrame();
    // for (const auto& figure : figures) {
    //     figure->draw(*this);
    // }

    for (int i = 0; i < this->height; ++i) {
        std::cout << '|';
        for (int j = 0; j < this->width; ++j) {
            std::cout << this->canvas[i][j];
        }
        std::cout << "|\n";
    }

    drawFrame();
}

// void ASCIICanvas::addFigure(std::shared_ptr<Figure> fig) {
//     figures.push_back(fig);
// }

void ASCIICanvas::setPixel(int x, int y, char c) {
    if (x >= 0 && x < this->width && y >= 0 && y < this->height) {
        this->canvas[y][x] = c;
    }
}

void ASCIICanvas::drawFrame() {
    std::cout << '|';
    for (int i = 0; i < this->width; ++i) {
        std::cout << '=';
    }
    std::cout << "|\n";
}


void ASCIICanvas::setDimension(int widthArg, int heightArg) {
    this->width = widthArg;
    this->height = heightArg;
};
