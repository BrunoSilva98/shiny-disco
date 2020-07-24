#ifndef __BITMAPFILEHEADER_H__
#define __BITMAPFILEHEADER_H__

#include <cstdint>

#pragma pack(2)
namespace bmp {
struct BitMapFileHeader
{
    char header[2]{'B', 'M'};
    std::int32_t fileSize;
    std::int32_t reserved{0};
    std::int32_t dataOffset;
};
}

#endif // __BITMAPFILEHEADER_H__