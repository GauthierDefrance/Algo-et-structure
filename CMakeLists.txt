cmake_minimum_required(VERSION 3.20)
project(TP1 C)

set(CMAKE_C_STANDARD 11)

add_executable(TP1
        TP1/main.c
        TP1/Sorting.c
        Tools/Tools.c
        Tools/Tools.h
        Tools/FileReading.c
        Tools/FileReading.h
)