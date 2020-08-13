#ifndef __RGB_H__
#define __RGB_H__

namespace bmp{

class Rgb
{
public:
    double m_red;
    double m_green;
    double m_blue;
    Rgb(double r, double g, double b);
};

Rgb operator-(const Rgb& first, const Rgb& second);

}
#endif // __RGB_H__