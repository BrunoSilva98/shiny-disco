cmake_minimum_required(VERSION 3.0.0)
project(shiny-disco VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(shiny-disco 
    main.cpp
    Bitmap.cpp 
    Mandelbrot.cpp
    ZoomList.cpp
    FractalCreator.cpp
    Rgb.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
