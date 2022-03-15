cmake_minimum_required(VERSION 3.21)
project(numerki)

set(CMAKE_CXX_STANDARD 14)

add_executable(numerki
        numerki_zad1.cpp functions.cpp functions.h gnuplot.h)