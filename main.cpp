#include "Figures/Figures.h"
#include "Canvas.h"
#include "ASCIICanvas.h"
#include "ConfReader.h"
#include <filesystem>
#include <iostream>
#include <string>
#include <memory>

#ifdef _WIN32
    void clearScreen() {
        system("cls");
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
    
    std::cout << "Ok" << std::endl;

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

    // std::cout << " Conf size: " << canvasHeight << " " << canvasWidgth << " out: " << canvasOutPut << " char:"<< bgChar<<";" << std::endl;


    ASCIICanvas canvas(canvasWidgth, canvasHeight, bgChar);
    canvas.draw();
    
    Rectangle rectangle(1, 2, 1, 2);
    rectangle.setSymbol('#');
    rectangle.draw(canvas);

    Rectangle rectangle2(3, 3, 2, 2);
    rectangle2.setSymbol('#');
    rectangle2.draw(canvas);

    // Należy zaimplementować metode wczytującą plik konfiguracyjny
    // i na jego podstawie tworzyć obiekt canvas i listę figur
}
