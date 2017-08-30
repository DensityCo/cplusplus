cmake_minimum_required (VERSION 2.8.10.2)
project(opencv)

if(NOT DEFINED CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE DEBUG)
endif(NOT DEFINED CMAKE_BUILD_TYPE)

if(APPLE)
include_directories("/usr/local/Cellar/opencv/3.3.0_3/include")
link_directories("/usr/local/Cellar/opencv/3.3.0_3/lib")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g -std=c++14")
set(CMAKE_C_FLAGS_RELEASE   "-O3 -std=c11")
set(CMAKE_C_FLAGS_DEBUG     "-O0 -g -std=c11")
else(APPLE)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -ggdb -g3 -std=c++11")
set(CMAKE_C_FLAGS_RELEASE   "-O3 -std=c11")
set(CMAKE_C_FLAGS_DEBUG     "-O0 -ggdb -g3 -std=c11")
endif(APPLE)

add_executable(opencv opencv.cpp )

target_link_libraries(opencv libopencv_imgproc.dylib libopencv_video.dylib libopencv_videoio.dylib libopencv_text.dylib libopencv_core.dylib libopencv_highgui.dylib)
install(TARGETS opencv DESTINATION bin)

