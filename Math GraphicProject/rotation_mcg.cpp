#include <graphics.h>
#include <cmath>

void draw_line()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // orginal line
    setcolor(BLUE);
    line(100, 100, 100, 300);
    double angle = 180 * 3.14159 / 180.0; //rotation

    int x1 = 100;
    int y1 = 0;
    int x2 = 100;
    int y2 = 200;
    int centerX = (x1 + x2) / 2;
    int centerY = (y1 + y2) / 2;

   //distance between the line
    int distance = 100;

    // Rotatation
    int rotatedX1 = centerX + (x1 - centerX) * cos(angle) - (y1 - centerY) * sin(angle) + distance;
    int rotatedY1 = centerY + (x1 - centerX) * sin(angle) + (y1 - centerY) * cos(angle) + distance;
    int rotatedX2 = centerX + (x2 - centerX) * cos(angle) - (y2 - centerY) * sin(angle) + distance;
    int rotatedY2 = centerY + (x2 - centerX) * sin(angle) + (y2 - centerY) * cos(angle) + distance;

    // Rotated line
    setcolor(RED);
    line(rotatedX1, rotatedY1, rotatedX2, rotatedY2);

  
    delay(5000);
    closegraph();
}

int main()
{
    draw_line();
    return 0;
}
