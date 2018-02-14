cmake_minimum_required(VERSION 3.9)
project(ML_Algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(ML_Algorithms main.cpp Library/Function.cpp Library/Function.h Library/Numerical_Analysis.cpp Library/Numerical_Analysis.h)