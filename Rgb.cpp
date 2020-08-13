#include "Rgb.h"

namespace bmp
{
    Rgb::Rgb(double r, double g, double b): m_red(r), m_green(g), m_blue(b)
    {
        
    }
    
    Rgb operator-(const Rgb& first, const Rgb& second) 
    {
        return Rgb(first.m_red - second.m_red, first.m_green - second.m_green, first.m_blue - second.m_blue);
    }

}