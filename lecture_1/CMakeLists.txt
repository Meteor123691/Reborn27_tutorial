cmake_minimum_required(VERSION 3.10)
project(OpenCVDemo)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(opencv_demo main.cpp)
target_link_libraries(opencv_demo ${OpenCV_LIBS})
target_include_directories(opencv_demo PRIVATE ${OpenCV_INCLUDE_DIRS})

