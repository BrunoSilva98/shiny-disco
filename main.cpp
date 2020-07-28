#include <iostream>
#include <cstdint>
#include <memory>

#include "Bitmap.h"
#include "Mandelbrot.h"

int main(int, char**) {
    const int WIDTH = 800;
    const int HEIGHT = 600;

    bmp::Bitmap bitmap(WIDTH, HEIGHT);
    double min = 999999;
    double max = -999999;

    std::unique_ptr<int[]> histogram(new int[bmp::Mandelbrot::MAX_ITERATIONS]{});
    std::unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{});

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            double xFractal = (x - WIDTH/2 - 200) * 2.0/HEIGHT;
            double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;

            int iterations = bmp::Mandelbrot::getIterations(xFractal, yFractal);
            fractal[y*WIDTH+x] = iterations;

            if (iterations != bmp::Mandelbrot::MAX_ITERATIONS)
                histogram[iterations]++;
        }   
    }

    int total = 0;
    for(int i=0; i<bmp::Mandelbrot::MAX_ITERATIONS; i++)
    {
        total += histogram[i];
    }

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            int iterations = fractal[y * WIDTH + x];
           
            double hue = 0.0;
            for (int i = 0; i < iterations; i++)
            {
                hue += ((double)histogram[i]) / total;
            }
            
            std::uint8_t red = 0;
            std::uint8_t green = hue * 255;
            std::uint8_t blue = 0;

            bitmap.setPixel(x, y, red, green, blue);
            
        }
        
    }
    

    bitmap.write("test.bmp");
    return 0;
}
