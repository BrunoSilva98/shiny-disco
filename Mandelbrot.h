#ifndef __MANDELBROT_H__
#define __MANDELBROT_H__

namespace bmp{

class Mandelbrot
{
public:
    static const int MAX_ITERATIONS = 1000;
    Mandelbrot(/* args */);
    ~Mandelbrot();
    static int getIterations(double x, double y);
};

}
#endif // __MANDELBROT_H__