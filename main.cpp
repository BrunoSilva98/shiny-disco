#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include <utility>

#include "FractalCreator.h"

int main(int, char**) {
    const int m_height = 600;

    bmp::FractalCreator fractalCreator(800, 600);
    fractalCreator.addZoom(bmp::Zoom(295, m_height - 202, 0.1));
    fractalCreator.addZoom(bmp::Zoom(312, m_height - 304, 0.1));
    fractalCreator.calculateIteration();
    fractalCreator.calculateTotalIterations();
    fractalCreator.drawFractal();
    fractalCreator.writeBitmap("test.bmp");
    return 0;
}
