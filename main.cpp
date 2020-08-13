#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include <utility>

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "Zoom.h"
#include "ZoomList.h"

int main(int, char**) {
    const int WIDTH = 800;
    const int HEIGHT = 600;

    bmp::Bitmap bitmap(WIDTH, HEIGHT);
    // double min = 999999;
    // double max = -999999;

    bmp::ZoomList zoomList(WIDTH, HEIGHT);
    zoomList.add(bmp::Zoom(WIDTH/2, HEIGHT/2, 3.0/WIDTH));

    std::unique_ptr<int[]> histogram(new int[bmp::Mandelbrot::MAX_ITERATIONS]{});
    std::unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{});

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            std::pair<double, double> coords = zoomList.doZoom(x, y);

            int iterations = bmp::Mandelbrot::getIterations(coords.first, coords.second);
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
            std::uint8_t red = 0;
            std::uint8_t green = 0;
            std::uint8_t blue = 0;
            int iterations = fractal[y * WIDTH + x];
           
            if (iterations != bmp::Mandelbrot::MAX_ITERATIONS)
            {
                double hue = 0.0;
                for (int i = 0; i < iterations; i++)  
                {
                    hue += ((double)histogram[i]) / total;
                }
                
                green = pow(255, hue);
            }
            bitmap.setPixel(x, y, red, green, blue);
            
        }
        
    }
    

    bitmap.write("test.bmp");
    return 0;
}
