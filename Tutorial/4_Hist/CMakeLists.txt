cmake_minimum_required(VERSION 3.13)
project(Colors)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(histograms histograms.cpp)
add_executable(contentFinder contentFinder.cpp)
add_executable(finder finder.cpp)
add_executable(integral integral.cpp)
add_executable(retrieve retrieve.cpp)
add_executable(tracking tracking.cpp)

target_link_libraries(histograms ${OpenCV_LIBS})
target_link_libraries(contentFinder ${OpenCV_LIBS})
target_link_libraries(finder ${OpenCV_LIBS})
target_link_libraries(integral ${OpenCV_LIBS})
target_link_libraries(retrieve ${OpenCV_LIBS})
target_link_libraries(tracking ${OpenCV_LIBS})

