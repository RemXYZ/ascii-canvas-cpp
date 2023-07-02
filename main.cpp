#include "Figures/Figures.h"
#include "Canvas.h"
#include "ASCIICanvas.h"
#include "ConfReader.h"
#include "ShapeParser.h"
#include "Light.h"


#include <filesystem>
#include <iostream>
#include <string>
#include <memory>

#ifdef _WIN32
    void clearScreen() {
        // system("cls");
        cout << "\n";
    }
#else
    void clearScreen() {
        system("clear");
    }
#endif

void tokenize(std::string& s, std::string& del)
{
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        std::cout << s.substr(start, end - start) << std::endl;
    } while (end != -1);
}


int main(int argc, char *argv[]) {

    // READING THE FILE
    std::string fileName;
    if (argc > 1) {
        fileName = argv[1];
        std::filesystem::path filePath(argv[1]);
        if (std::filesystem::is_regular_file(filePath)) {
            std::cout << "Argument " << filePath << " is a regular file." << std::endl;
        } else {
            std::cout << "Argument " << filePath << " is not a regular file." << std::endl;
        }
    } else {
        std::cout << "No arguments provided." << std::endl;
        return -1;
    }

    ConfReader confReader(fileName);
    int canvasWidgth = confReader.getCanvasWidth();
    int canvasHeight = confReader.getCanvasHeight();
    std::string canvasOutPut = confReader.getOutputFile();
    char bgChar = confReader.getBackgroundChar();
    std::vector<std::string> canvasShapesRaw = confReader.getShapes();
    std::vector<int> lightData = confReader.getLight();

    // std::cout << " Conf size: " << canvasHeight << " " << canvasWidgth << " out: " << canvasOutPut << " char:"<< bgChar<<";" << std::endl;


    ASCIICanvas canvas(canvasWidgth, canvasHeight, bgChar, canvasOutPut);
    canvas.setOutputFile(canvasOutPut);
    // canvas.draw();
    

    // Triangle triangle(5,5,4,4);
    // triangle.setSymbol('#');
    // triangle.draw(canvas);

    // Square rectangle(1, 2, 2);
    // rectangle.setSymbol('#');
    // rectangle.draw(canvas);


    // Pixel pixel(10, 10);
    // pixel.setSymbol('@');
    // pixel.draw(canvas);

    // Pixel pixel2(6, 6);
    // pixel2.draw(canvas);

    // Rectangle rectangle2(3, 3, 2, 2);
    // rectangle2.setSymbol('#');
    // rectangle2.draw(canvas);

    // Figure *hello = nullptr;

    // hello = new Rectangle(1,1,2,2);
    // hello->setSymbol('@');
    // hello->draw(canvas);


    ShapeParser shapeParser(canvasShapesRaw);
    const std::vector<std::unique_ptr<Figure>>& shapes = shapeParser.getShapes();
    for (auto& shape: shapes){
        // shape->hello();
        shape->draw(canvas);
    }

    if (lightData[0] == 1) {
        Light light(lightData[1],lightData[2], canvas);
        light.castShadow(canvas);
    }
    
    

    canvas.draw();
    cout << "Image saved in: " << canvasOutPut << endl;
}
