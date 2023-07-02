# ascii-canvas-cpp

This project aims to implement a system for creating ASCII art. The system includes classes to represent a "canvas" onto which shapes will be drawn and the shapes themselves. It also uses a configuration file to define various parameters for the drawing, such as the dimensions of the canvas, the symbols to use for drawing, and the shapes to draw.

Here's how to get started:

## Project Retrieval

1.You need to clone the project from GitHub. Make sure you have git installed on your machine and then run the following command in your terminal:
bash
Copy code

git clone https://github.com/RemXYZ/ascii-canvas-cpp.git

## Compilation

This project is assumed to be written in C++ or a similar language that can be compiled with a compiler like g++. To compile the code, navigate into the project directory using your terminal and run the command:
```
g++ main.cpp ASCIICanvas.cpp -o main
```
Or use make command:
```
make
```

This will compile all C++ files in the directory into an executable file named 'main'.

## Usage
You can run the project by executing the 'main' file from the terminal with a configuration file as the argument. 
The configuration file should specify parameters such as the dimensions of the canvas, the output file name, the symbol for non-shape pixels, and a list of shapes to draw with their respective coordinates, dimensions, and symbols. Here is an example command to run the project:
```
./main config.conf
```
Replace 'config.conf' with the path to your configuration file.

You also have a sample file to study: <br>
config.conf


## Shapes:

1. Rectangle
2. Square
3. Pixel
4. Triangle
5. Circle

_You can also modify or add more figures in Figure/Figures.h file_

## Light
There is also point light source that shines uniformly in all directions on the canvas (Light). This light source should cast shadows from the figures, with the shadow symbol and the light source location defined in the configuration file.