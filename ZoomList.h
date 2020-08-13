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
    ~ZoomList();
    void add(const Zoom& zoom);
    std::pair<double, double> doZoom(int x, int y);
    
private:
    int m_width;
    int m_height;
    std::vector<Zoom> m_zooms;
};

}

#endif // __ZOOMLIST_H__