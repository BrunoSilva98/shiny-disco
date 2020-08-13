#ifndef __ZOOMLIST_H__
#define __ZOOMLIST_H__

#include <vector>
#include <utility>
#include "Zoom.h"

namespace bmp{

class ZoomList
{
public:
    ZoomList(int width, int height);
    void add(const Zoom& zoom);
    std::pair<double, double> doZoom(int x, int y);

private:
    int m_width{0};
    int m_height{0};
    double m_xCenter{0};
    double m_yCenter{0};
    double m_scale{1.0};
    std::vector<Zoom> m_zooms;
};

}

#endif // __ZOOMLIST_H__