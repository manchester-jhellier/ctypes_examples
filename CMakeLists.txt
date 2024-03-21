cmake_minimum_required(VERSION 3.27)
project(cxx_library_tests)

set(CMAKE_CXX_STANDARD 17)

add_executable(cxx_library_tests main.cpp
        add_seven.cpp
        array_recasting.h
        array_recasting.cpp
        int_seven.cpp
        int_seven.h
        array_seven.cpp
        array_seven.h
)
