#include <iostream>

#include "Bitmap.h"

int main(int, char**) {
    const int WIDTH = 800;
    const int HEIGHT = 600;

    bmp::Bitmap bitmap(WIDTH, HEIGHT);

    for (size_t y = 0; y < HEIGHT; y++)
    {
        for (size_t x = 0; x < WIDTH; x++)
        {
            bitmap.setPixel(x, y, 255, 0, 0);
        }
        
    }
    
    bitmap.write("test.bmp");
    return 0;
}
