#include "../ASCIICanvas.h"
#include <cmath>

using namespace std;
#ifndef FIGURE_H
#define FIGURE_H
class Figure {
public:
    virtual ~Figure() = default;
    virtual void draw(ASCIICanvas &c) = 0;
    virtual void setSymbol(char symbol) {
        this->symbol = symbol;
    }
    virtual void hello() {
        cout << "This is Figure" << endl;
    }
protected:
    char symbol = '#';
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
        // canvas.draw();
    }

    void hello()override {
        cout << "This is Rectangle" << endl;
    }
    
    

private:
    int x, y, width, height;
};
#endif

#ifndef SQUERE_H
#define SQUERE_H
class Square : public Rectangle {
public:
    Square(int x, int y, int size) :Rectangle(x, y, size, size) {}
    void hello() override {
        cout << "This is Square" << endl;
    }
private:
    int x, y, size;
};
#endif


#ifndef PIXEL_H
#define PIXEL_H
class Pixel : public Square {
public:
    Pixel(int x, int y) : Square(x, y, 1) {}
    void hello() override {
        cout << "This is Pixel" << endl;
    }
private:
    int x, y, size;
};
#endif


#ifndef TRIANGLE
#define TRIANGLE
class Triangle : public Figure {
public:
    Triangle(int x, int y, int base, int height) : x(x), y(y), base(base), height(height) {}
    void draw(ASCIICanvas &c) override {
        int halfBase = base / 2;

        // Rysowanie trójkąta
        for (int i = 0; i < height; i++) {
            int start = x - i;
            int end = x + i;

            // Aby rysować trójkąt w dół, trzeba zacząć od "góry"
            int currentY = y - halfBase + i;

            for (int j = start; j <= end; j++) {
                c.setPixel(j, currentY, symbol);
            }
        }
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
        for (int i = x - radius; i <= x + radius; i++) {
            for (int j = y - radius; j <= y + radius; j++) {
                if (std::pow(i - x, 2) + std::pow(j - y, 2) <= std::pow(radius, 2)) {
                    c.setPixel(i, j, symbol);
                }
            }
        }
    }
private:
    int x, y, radius;
};
#endif
