cmake_minimum_required(VERSION 3.13)
project(Colors)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(colorDetection colorDetection.cpp)
add_executable(extractObject extractObject.cpp)
add_executable(huesaturation huesaturation.cpp)

target_link_libraries(colorDetection ${OpenCV_LIBS})
target_link_libraries(extractObject ${OpenCV_LIBS})
target_link_libraries(huesaturation ${OpenCV_LIBS})

