cmake_minimum_required(VERSION 3.20.0)
project(Lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab4 main.cpp StringHash.hpp StringHash.cpp
        ChainHash.hpp
        ChainHash.cpp
        ChainLink.hpp
        ChainLink.cpp)