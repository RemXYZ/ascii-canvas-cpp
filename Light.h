#ifndef LIGHT_H
#define LIGHT_H
#include <cmath>
#include "ASCIICanvas.h"
using namespace std;

class Light {
public:
    Light(int x, int y, ASCIICanvas &c) : x(x), y(y) {
        c.setPixel(x,y, '*');
    }
    int getX() const { return x; }
    int getY() const { return y; }
        //...
    void castShadow(ASCIICanvas &c) {
        for (int degree = 0; degree <= 90; degree++) {
            castRay(c, degree, -1, 1, false); 
        }
        
        for (int degree = 91; degree <= 180; degree++) {
            castRay(c, degree-90, 1, 1, true);
            // cout << "STOPIEN: "<< degree << endl;
        }
        for (int degree = 181; degree <= 270; degree++) {
            castRay(c, degree-180, 1, -1, false);
        }
        for (int degree = 271; degree < 360; degree++) {
            castRay(c, degree-270, -1, -1, true);
        }
    }


    void castRay(ASCIICanvas &c, int degree, int xDir, int yDir, bool swap) {
        bool hasHitObject = false;
        float radian = degree * (M_PI / 180);
        int r = 1;
        bool flash = true;
        int trigCalcX;
        int trigCalcY;
        int curx,cury;

        while (flash) {
            // if (r > c.getWidth() || r > c.getHeight() || r < 0) {
            //     break;
            // }
            
            if (swap) {
                curx = round(x + r * sin(radian) * xDir);
                cury = round(y + r * cos(radian) * yDir);
            }else {
                curx = round(x + r * cos(radian) * xDir);
                cury = round(y + r * sin(radian) * yDir);
            }
            
            if (curx < 0 || curx >= c.getWidth() || cury < 0 || cury >= c.getHeight()) {
                break;
            }
            if (!hasHitObject && c.getPixel(curx, cury) != ' ') {
                hasHitObject = true;
            }
            if (hasHitObject && c.getPixel(curx, cury) == ' ') {
                c.setPixel(curx, cury, shadowSymbol);
            }

            // cout << "x: " << curx << " y: " << cury << " rad cos: " << radian  << endl;


            r++;
        }

        //////
        // for (int r = 0; r < max(c.getWidth(), c.getHeight()); r++) {
        //     int curX = round(x + r * cos(radian));
        //     int curY = round(y + r * sin(radian));

        //     // Ensure we are within the canvas boundaries
        //     if (curX < 0 || curX >= c.getWidth() || curY < 0 || curY >= c.getHeight()) {
        //         break;
        //     }

        //     // If we've hit an object start drawing shadow
        //     if (!hasHitObject && c.getPixel(curX, curY) != ' ') {
        //         hasHitObject = true;
        //     } else if (hasHitObject) {
        //         c.setPixel(curX, curY, shadowSymbol);
        //     }
        // }
    }
private:
    int x, y;
    char shadowSymbol = '.';
};

#endif