#include <iostream>

#include "FractalCreator.h"
#include "Rgb.h"

int main(int, char**) {
    bmp::FractalCreator fractalCreator(800, 600);

    fractalCreator.addRange(0.0, bmp::Rgb(150, 121, 169));
    fractalCreator.addRange(0.3, bmp::Rgb(10, 50, 255));
    fractalCreator.addRange(0.5, bmp::Rgb(255, 80, 25));
    fractalCreator.addRange(1.0, bmp::Rgb(80, 255, 100));
    
    fractalCreator.addZoom(bmp::Zoom(295, fractalCreator.getHeight() - 202, 0.1));
    fractalCreator.addZoom(bmp::Zoom(312, fractalCreator.getHeight() - 304, 0.1));
    fractalCreator.run("test.bmp");
    return 0;
}
