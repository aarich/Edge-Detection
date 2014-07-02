cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
 
project(edgeDetect)

find_package( OpenCV REQUIRED )
find_package(Boost REQUIRED)

add_executable(edgeDetect src/main.cpp)

include_directories(SYSTEM ${OpenCV_INCLUDE_DIRS})

target_link_libraries (edgeDetect ${OpenCV_LIBRARIES})