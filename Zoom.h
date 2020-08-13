#ifndef __ZOOM_H__
#define __ZOOM_H__

namespace bmp{

struct Zoom
{
    int x;
    int y;
    double scale;

    Zoom(int x, int y, double scale) : x(x), y(y), scale(scale) {};
};
    
} // namespace bmp

#endif // __ZOOM_H__