#ifndef CONFREADER_H
#define CONFREADER_H

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <regex>

#include <map>
#include <memory>
#include <functional>
#include "Figures/Figures.h"
#include "Light.h"


class ConfReader {
private:
    int canvasHeight, canvasWidth;
    std::string outputFile;
    char backgroundChar;
    std::vector<std::string> shapes;
    // lightData [*EXIST*, *X*, *Y*]
    vector<int> lightData = {0,0,0};

public:
    ConfReader(const std::string& filename) {
        std::ifstream fd(filename);
        if (!fd.is_open()) {
            return;
        }
        std::string line;
        while (getline(fd, line)) {
            std::istringstream iss(line);
            std::string word;
            iss >> word;
            
            // Size of canvas
            if (word == "CANVAS") {
                iss >> canvasWidth >> canvasHeight;
                // Sprawdzenie, czy przypisanie do zmiennych powiodło się i wartości są większe od 0
                if (iss.fail() || canvasHeight <= 0 || canvasWidth <= 0) {
                    std::cerr << "Invalid canvas dimensions\n";
                    return;
                }
                iss.clear();
            } 
            // The filename of how I will save the canvas
            else if (word == "OUTFILE") {
                iss >> outputFile;
                // Sprawdzenie, czy przypisanie do zmiennej powiodło się i string nie jest pusty
                if (iss.fail() || outputFile.empty()) {
                    std::cerr << "Invalid output file name\n";
                    return;
                }
                iss.clear();
            }
            // The Background symbol
            else if (word == "BACKGROUND") {
                // I'm looking for the symbol " "
                std::regex pattern("(\\w+)\\s+'(.*?)'");  // Wyrażenie regularne pasujące do słowa, spacji, cudzysłowów, dowolnych znaków, cudzysłowów
                std::smatch matches;
                if (std::regex_search(line, matches, pattern)) {
                    if (matches[2].length() > 0) {
                        backgroundChar = matches[2].str()[0];
                        // std::cout << "Value:" << backgroundChar << "s\n";
                    } else {
                        std::cout << "No value found\n";
                    }
                } else {
                    std::cout << "No match found\n";
                }
            } 
            else if (word == "SHAPE") {
                std::string lineShape;
                getline(iss, lineShape);
                if (iss.fail()) {
                    std::cerr << "Invalid SHAPE\n";
                    return;
                }
                shapes.push_back(lineShape.substr(1)); // skip the space at the start
            }
            else if (word == "LIGHT") {
                int x, y;
                if (!(iss >> x >> y)) {
                    std::cerr << "Invalid parameters for light\n";
                    continue;
                }
                lightData[0] = 1;
                lightData[1] = x;
                lightData[2] = y;
                
            }
        }
        fd.close();
    }

    int getCanvasHeight() const {
        return canvasHeight;
    }

    int getCanvasWidth() const {
        return canvasWidth;
    }

    std::string getOutputFile() const {
        return outputFile;
    }

    char getBackgroundChar() const {
        return backgroundChar;
    }

    std::vector<std::string> getShapes() const {
        return shapes;
    }

    vector<int> getLight() const {
        return lightData;
    }
};



#endif



// std::vector<std::unique_ptr<Figure>> parseShapes(const std::vector<std::string>& shapes) {
//     std::vector<std::unique_ptr<Figure>> result;
//     shapeFactories["Rectangle"] = [](std::istringstream& iss) {
//         int x, y, width, height;
//         char symbol;
//         iss >> x >> y >> width >> height >> symbol;
//         return std::make_unique<Rectangle>(x, y, width, height, symbol);
//     };
    // // Ustalamy mapę funkcji tworzących obiekty poszczególnych klas
    // std::map<std::string, std::function<std::unique_ptr<Figure>(std::istringstream&)>> shapeFactories;
    // shapeFactories["Square"] = [](std::istringstream& iss) {
    //     int x, y, side;
    //     char symbol;
    //     iss >> x >> y >> side >> symbol;
    //     return std::make_unique<Square>(x, y, side, symbol);
    // };
    // shapeFactories["Circle"] = [](std::istringstream& iss) {
    //     int x, y, radius;
    //     char symbol;
    //     iss >> x >> y >> radius >> symbol;
    //     return std::make_unique<Circle>(x, y, radius, symbol);
    // };
    // shapeFactories["Triangle"] = [](std::istringstream& iss) {
    //     int x, y, base, height;
    //     char symbol;
    //     iss >> x >> y >> base >> height >> symbol;
    //     return std::make_unique<Triangle>(x, y, base, height, symbol);
    // };

    // // Przechodzimy przez wszystkie linie w "shapes" i tworzymy obiekty figur
    // for (const auto& shape : shapes) {
    //     std::istringstream iss(shape);
    //     std::string shapeType;
    //     iss >> shapeType;
    //     if (shapeFactories.count(shapeType) > 0) {
    //         result.push_back(shapeFactories[shapeType](iss));
    //     } else {
    //         std::cout << "Unrecognized shape type: " << shapeType << std::endl;
    //     }
    // }

//     return result;
// }
