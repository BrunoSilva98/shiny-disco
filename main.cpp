#include <iostream>
#include <cstdint>

#include "Bitmap.h"
#include "Mandelbrot.h"

int main(int, char**) {
    const int WIDTH = 800;
    const int HEIGHT = 600;

    bmp::Bitmap bitmap(WIDTH, HEIGHT);
    double min = 999999;
    double max = -999999;

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            double xFractal = (x - WIDTH/2) * (2.0/WIDTH);
            double yFractal = (y - HEIGHT/2) * (2.0/HEIGHT);

            int iterations = bmp::Mandelbrot::getIterations(xFractal, yFractal);
            std::uint8_t red = (std::uint8_t)(255 * (double)iterations / bmp::Mandelbrot::MAX_ITERATIONS);
            
            bitmap.setPixel(x, y, red, red, 0);
            if (red < min) min = red;
            if (red > max) max = red;
        }
        
    }
    std::cout << min << " " << max << std::endl;

    bitmap.write("test.bmp");
    return 0;
}
