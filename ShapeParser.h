#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

#include "Figures/Figures.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;
char getSymbol(std::string line) {
    // I'm looking for the symbol " "
     char backgroundChar;
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

    return backgroundChar;
}



std::string toLower(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(), 
                   [](unsigned char c){ return std::tolower(c); });
    return result;
}



class ShapeParser {
public:
    ShapeParser(const std::vector<std::string>& lines) {
        for (const auto& line : lines) {
            std::istringstream iss(line);
            std::string shapeNameRaw;
            if (!(iss >> shapeNameRaw)) {
                std::cerr << "Invalid shape line\n";
                continue;
            }
            std::string shapeName = toLower(shapeNameRaw);
            
            if (shapeName == "rectangle") {
                int x, y, width, height;
                
                char symbol = getSymbol(line);
                if (!(iss >> x >> y >> width >> height)) {
                    std::cerr << "Invalid parameters for Rectangle\n";
                    continue;
                }
                auto rectangle = std::make_unique<Rectangle>(x, y, width, height);
                rectangle->setSymbol(symbol);
                shapes.push_back(std::move(rectangle));
            } 
            else if (shapeName == "square") {
                int x, y, size;
                char symbol = getSymbol(line);
                if (!(iss >> x >> y >> size)) {
                    std::cerr << "Invalid parameters for Square\n";
                    continue;
                }

                auto squere = std::make_unique<Square>(x, y, size);
                squere->setSymbol(symbol);
                shapes.push_back(std::move(squere));
            }

            else if (shapeName == "pixel") {
                int x, y, size;
                char symbol = getSymbol(line);
                if (!(iss >> x >> y)) {
                    std::cerr << "Invalid parameters for SqPixeluare\n";
                    continue;
                }
                auto pixel = std::make_unique<Pixel>(x, y);
                pixel->setSymbol(symbol);
                shapes.push_back(std::move(pixel));
            }

            
            else if (shapeName == "triangle") {
                int x, y, base, height;
                char symbol = getSymbol(line);
                if (!(iss >> x >> y >> base >> height)) {
                    std::cerr << "Invalid parameters for Triangle\n";
                    continue;
                }
                auto triangle = std::make_unique<Triangle>(x, y, base, height);
                triangle->setSymbol(symbol);
                shapes.push_back(std::move(triangle));
            } 
            else if (shapeName == "circle") {
                int x, y, radius;
                char symbol = getSymbol(line);
                if (!(iss >> x >> y >> radius)) {
                    std::cerr << "Invalid parameters for Circle\n";
                    continue;
                }
                auto circle = std::make_unique<Circle>(x, y, radius);
                circle->setSymbol(symbol);
                shapes.push_back(std::move(circle));
            }
            else {
                std::cerr << "Unknown shape: " << shapeName << "\n";
            }
        }
    }
    
    const std::vector<std::unique_ptr<Figure>>& getShapes() const {
        return shapes;
    }

private:
    std::vector<std::unique_ptr<Figure>> shapes;
};

#endif