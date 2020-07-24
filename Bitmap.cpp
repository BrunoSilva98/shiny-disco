#include <fstream>

#include "Bitmap.h"
#include "BitMapInfoHeader.h"
#include "BitMapFileHeader.h"

namespace bmp {

Bitmap::Bitmap(int width, int height): m_width(width), m_height(height),
            m_pixels(new uint8_t[width * height * 3]{})
{
}

Bitmap::~Bitmap(){}

bool Bitmap::write(std::string filename) 
{
    BitMapFileHeader fileHeader;
    BitMapInfoHeader infoHeader;
    auto headerSizes = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader);
    auto totalPixels = m_height * m_width * 3;

    fileHeader.fileSize = headerSizes + totalPixels;
    fileHeader.dataOffset = headerSizes;

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    std::ofstream file;
    file.open(filename.c_str(), std::ios::out|std::ios::binary);

    if (!file)
    {
        return false;
    }
    
    file.write((char *)&fileHeader, sizeof(fileHeader));
    file.write((char *)&infoHeader, sizeof(infoHeader));
    file.write((char *)m_pixels.get(), totalPixels);
    file.close();
    return true;
}

void Bitmap::setPixel(int x, int y, std::uint8_t red, std::uint8_t green,
                    std::uint8_t blue) 
{
    std::uint8_t *pixel = m_pixels.get();
    pixel += ((y * 3) * m_width) + (x * 3);
    pixel[0] = blue;
    pixel[1] = green;
    pixel[2] = red;
}
    
}