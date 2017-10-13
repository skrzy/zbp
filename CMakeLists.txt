cmake_minimum_required(VERSION 3.8)
project(zbp)

set(CMAKE_CXX_STANDARD 17)

include_directories(/home/kstrek/workspace/boost_1_65_1/)

set(SOURCE_FILES main.cpp Z1.cpp Z1.h Z2.cpp Z2.h)
add_executable(zbp1 ${SOURCE_FILES})