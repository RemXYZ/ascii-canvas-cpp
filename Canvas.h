#ifndef CANVAS_H
#define CANVAS_H
#include <vector>
#include <memory>

class Canvas {
public:
    virtual ~Canvas() = default;
    virtual void setDimension(int width, int height) = 0;
    virtual void draw() = 0;

    virtual int getWidth() {
        return width;
    }
    virtual int getHeight() {
        return height;
    }
    virtual int getBGSymbol() {
        return bgSymbol;
    }
    // virtual void addFigure(std::shared_ptr<Figure> fig) = 0;
protected:
    int height;
    int width;
    char bgSymbol;
    // std::vector<std::shared_ptr<Figure>> figures;
};
#endif // CANVAS_H