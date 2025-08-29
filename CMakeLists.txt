cmake_minimum_required(VERSION 3.15...4.0)
project(improved-fraction VERSION 0.5 
                          DESCRIPTION "A improved fraction class from my class"
                          LANGUAGES CXX
)

add_library(fractionlib lib/fraction.cpp lib/fraction.hpp)
add_executable(fraction main.cpp lib/fraction.cpp)
