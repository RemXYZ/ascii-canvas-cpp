#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class ConfReader {
private:
    int canvasHeight, canvasWidth;
    std::string outputFile;
    char backgroundChar;
    std::vector<std::string> shapes;

public:
    ConfReader(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string word;
            iss >> word;
            if (word == "CANVAS") {
                iss >> canvasHeight >> canvasWidth;
            } else if (word == "OUTFILE") {
                iss >> outputFile;
            } else if (word == "BACKGROUND") {
                iss >> backgroundChar;
            } else if (word == "SHAPE") {
                getline(iss, line);
                shapes.push_back(line.substr(1)); // skip the space at the start
            }
        }
        file.close();
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
};
