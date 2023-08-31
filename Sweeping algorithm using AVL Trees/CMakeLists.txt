cmake_minimum_required(VERSION 3.25)
project(labSD5)

set(CMAKE_CXX_STANDARD 17)

add_executable(labSD5 main.cpp Segment.cpp Segment.h Event.cpp Event.h AVL.cpp AVL.h)
