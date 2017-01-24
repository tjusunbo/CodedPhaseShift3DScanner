cmake_minimum_required (VERSION 2.8.7)

project (3dScanner)

set (CMAKE_CXX_FLAGS "-std=c++0x -g")
set (CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/local/lib)
include_directories (BEFORE include)

add_subdirectory (src)


