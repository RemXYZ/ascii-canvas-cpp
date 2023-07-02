#include "Canvas.h"
#include "ASCIICanvas.h"
#include <fstream>
// #include "Figures/Figures.h"


void clearScreen();
using namespace std;

ASCIICanvas::ASCIICanvas(int widthArg, int heightArg, char bgSymbolArg, const std::string& output) {
    this->bgSymbol = bgSymbolArg;
    this->width = widthArg;
    this->height = heightArg;
    this->canvas.resize(height, std::vector<char>(width, bgSymbolArg));
    outfile.open(output);
    if (!outfile) {
        // Rzucanie wyjątku, jeśli otwarcie pliku się nie powiedzie
        throw std::runtime_error("Nie udało się otworzyć pliku " + output);
    }
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

    for (int i = 0; i < this->height; ++i) {
        outfile << '|';
        for (int j = 0; j < this->width; ++j) {
            outfile << this->canvas[i][j];
        }
        outfile << "|\n";
    }

    drawFrame();
     
}

// void ASCIICanvas::addFigure(std::shared_ptr<Figure> fig) {
//     figures.push_back(fig);
// }

void ASCIICanvas::drawFrame() {
    std::cout << '|';
    for (int i = 0; i < this->width; ++i) {
        std::cout << '=';
    }
    std::cout << "|\n";

    outfile << '|';
    for (int i = 0; i < this->width; ++i) {
        outfile << '=';
    }
    outfile << "|\n";
}


void ASCIICanvas::setDimension(int widthArg, int heightArg) {
    this->width = widthArg;
    this->height = heightArg;
};


int ASCIICanvas::setPixel(int x, int y, char c) {
    // if ((x > width || y > height) || (x<0 || y<0)) {
        
    // }
    if (x >= 0 && x < this->width && y >= 0 && y < this->height) {
        this->canvas[y][x] = c;
    }else {
        return 0;
    }
    return 1;
}


char ASCIICanvas::getPixel(int x, int y) {
    //!! Pozniej trzeba bedzie zwracac wskaznik na char
    char def = 1;
    if (x >= 0 && x < this->width && y >= 0 && y < this->height) {
        // def = this->canvas[y][x];
        return this->canvas[y][x];
    }else{
        def = 0;
        return 0;
    }
    return 1;
}


ASCIICanvas::~ASCIICanvas (){
    outfile.close();
}