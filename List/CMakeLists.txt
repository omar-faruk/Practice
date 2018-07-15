cmake_minimum_required(VERSION 3.9)
project(List)

set(CMAKE_CXX_STANDARD 11)

add_executable(List
        list_ptr.h
        main.cpp list.h)
