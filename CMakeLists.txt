cmake_minimum_required(VERSION 3.26)
project(occlusionCpp)

set(CMAKE_CXX_STANDARD 17)

# Point to the Clang compiler installed via Homebrew that supports OpenMP
set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")
set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")

# Manually adding -fopenmp to enable OpenMP and link to LLVMs library directory
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -L/opt/homebrew/opt/llvm/lib")

add_executable(occlusionCpp main.cpp
        Point.h
        Point.cpp
        Rectangle.h
        Rectangle.cpp
        generalUtils.h
        mathUtils.h
        sortUtils.h
        Timer.h)
