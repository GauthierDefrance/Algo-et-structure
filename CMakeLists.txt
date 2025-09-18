cmake_minimum_required(VERSION 3.20)
project(MesTPs C)

set(CMAKE_C_STANDARD 11)

add_executable(TP1
        TP1_and_2/main.c
        TP1_and_2/Sorting.c
        Tools/Tools.c
        Tools/Tools.h
        Tools/Types.h
        Tools/FileReading.c
        Tools/FileReading.h
)