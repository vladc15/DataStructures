cmake_minimum_required(VERSION 3.24)
project(labSD3)

set(CMAKE_CXX_STANDARD 17)

add_executable(labSD3 main.cpp Node_Linked.cpp Node_Linked.h LinkedList.cpp LinkedList.h Node_Skip.cpp Node_Skip.h SkipList.cpp SkipList.h)
