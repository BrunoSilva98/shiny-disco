#include <iostream>

#include "Bitmap.h"

int main(int, char**) {
    bmp::Bitmap bitmap(800, 600);
    bitmap.write("test.bmp");
    return 0;
}
