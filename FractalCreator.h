#ifndef __FRACTALCREATOR_H__
#define __FRACTALCREATOR_H__

#include <string>
#include "Zoom.h"
#include "Bitmap.h"
#include "ZoomList.h"

namespace bmp{

class FractalCreator
{
public:
    FractalCreator(int width, int height);
    void calculateIteration();
    void calculateTotalIterations();
    void drawFractal();
    void writeBitmap(std::string name);
    void addZoom(const Zoom& zoom);
    int getWidth();
    int getHeight();

private:
    int m_width;
    int m_height;
    int m_total;
    std::unique_ptr<int[]> m_histogram;
    std::unique_ptr<int[]> m_fractal;
    Bitmap m_bitmap;
    ZoomList m_zoomList;

};
}
#endif // __FRACTALCREATOR_H__