#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include <utility>

#include "FractalCreator.h"
#include "Rgb.h"

int main(int, char**) {
    bmp::FractalCreator fractalCreator(800, 600);
    fractalCreator.addZoom(bmp::Zoom(295, fractalCreator.getHeight() - 202, 0.1));
    fractalCreator.addZoom(bmp::Zoom(312, fractalCreator.getHeight() - 304, 0.1));
    fractalCreator.calculateIteration();
    fractalCreator.calculateTotalIterations();
    fractalCreator.drawFractal();
    fractalCreator.writeBitmap("test.bmp");
    return 0;
}
