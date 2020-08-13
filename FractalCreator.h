#ifndef __FRACTALCREATOR_H__
#define __FRACTALCREATOR_H__

#include <string>
#include "Zoom.h"

namespace bmp{

class FractalCreator
{
public:
    FractalCreator();
    ~FractalCreator();
    void calculateIteration();
    void drawFractal();
    void writeBitmap(std::string& name);
    void addZoom(const Zoom& zoom);
    
};
}
#endif // __FRACTALCREATOR_H__