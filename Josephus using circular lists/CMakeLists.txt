cmake_minimum_required(VERSION 3.24)
project(labSD2)

set(CMAKE_CXX_STANDARD 17)

add_executable(labSD2 main.cpp Node.cpp Node.h CircularList.cpp CircularList.h)
