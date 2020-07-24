#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <string>
#include <cstdint>
#include <memory>

namespace bmp{

class Bitmap
{
private:
    int m_width{0};
    int m_height{0};
    std::unique_ptr<std::uint8_t[]> m_pixels{nullptr};

public:
    Bitmap(int width, int height);
    ~Bitmap();
    bool write(std::string filename);
    void setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue);
};

}

#endif // __BITMAP_H__