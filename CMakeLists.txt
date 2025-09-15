cmake_minimum_required(VERSION 3.20)
project(MesTPs C)

set(CMAKE_C_STANDARD 11)

add_executable(TP1
        TP1/main.c
        TP1/Sorting.c
        Tools/Tools.c
        Tools/Tools.h
        Tools/Types.h
        Tools/FileReading.c
        Tools/FileReading.h
)

add_executable(TP2
        TP2/main.c
        TP2/Sorting.c
        TP2/Sorting.h
        Tools/Tools.c
        Tools/Tools.h
        Tools/Types.h
)