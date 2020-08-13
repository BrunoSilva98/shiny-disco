#ifndef __FRACTALCREATOR_H__
#define __FRACTALCREATOR_H__

#include <string>
#include <vector>
#include "Zoom.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "Rgb.h"

namespace bmp{

class FractalCreator
{
public:
    FractalCreator(int width, int height);
    void run(std::string name);
    void addZoom(const Zoom& zoom);
    int getHeight();
    void addRange(double rangeEnd, const Rgb& rgb);

private:
    int m_width;
    int m_height;
    int m_total;
    std::unique_ptr<int[]> m_histogram;
    std::unique_ptr<int[]> m_fractal;
    std::vector<int> m_ranges;
    std::vector<int> m_rangeTotals;
    std::vector<Rgb> m_colors;
    bool m_gotFirstRange{false};
    Bitmap m_bitmap;
    ZoomList m_zoomList;
    void calculateRangeTotals();
    void calculateIteration();
    void calculateTotalIterations();
    void drawFractal();
    void writeBitmap(std::string name);
    int getRange(int iterations) const;
};
}
#endif // __FRACTALCREATOR_H__