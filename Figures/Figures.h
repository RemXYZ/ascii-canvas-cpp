#include "../ASCIICanvas.h"

using namespace std;
#ifndef FIGURE_H
#define FIGURE_H
class Figure {
public:
    virtual ~Figure() = default;
    virtual void draw(ASCIICanvas &c) = 0;
    virtual void setSymbol(char symbol) = 0;
protected:
    char symbol;
};
#endif



#ifndef RECTANGLE
#define RECTANGLE 

class Rectangle : public Figure {
public:
    Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

    void draw(ASCIICanvas &canvas) override {
        for (int i = y; i < y + height; ++i) {
            for (int j = x; j < x + width; ++j) {
                canvas.setPixel(j, i, symbol);
            }
        }
        canvas.draw();
    }
    
    void setSymbol(char symbol) override {
        this->symbol = symbol;
    }

private:
    int x, y, width, height;
    char symbol;
};
#endif

#ifndef SQUERE_H
#define SQUERE_H
class Square : public Rectangle {
public:
    Square(int x, int y, int size) :Rectangle(x, y, size, size) {}
    void draw(ASCIICanvas &c) override {
        // Metoda do narysowania kwadratu
    }
    void setSymbol(char symbol) override {
        this->symbol = symbol;
    }
private:
    int x, y, size;
    char symbol;
};
#endif


#ifndef TRIANGLE
#define TRIANGLE
class Triangle : public Figure {
public:
    Triangle(int x, int y, int base, int height) : x(x), y(y), base(base), height(height) {}
    void draw(ASCIICanvas &c) override {
        // Metoda do narysowania trójkąta
    }
    void setSymbol(char symbol) override {
        this->symbol = symbol;
    }
private:
    int x, y, base, height;
};
#endif


#ifndef CIRCLE
#define CIRCLE
class Circle : public Figure {
public:
    Circle(int x, int y, int radius) : x(x), y(y), radius(radius) {}
    void draw(ASCIICanvas &c) override {
        // Metoda do narysowania koła
    }
    void setSymbol(char symbol) override {
        this->symbol = symbol;
    }
private:
    int x, y, radius;
};
#endif
