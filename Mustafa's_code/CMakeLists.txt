cmake_minimum_required(VERSION 3.27)
project(Assignment_Demo)

set(CMAKE_CXX_STANDARD 17)

add_executable( Assignment_Demo
        main.cpp
        Numerical_Tic-Tac-Toe.h
        # Implementation.cpp
        Connect_Four.h
        BoardGame_Classes.h
        "4 x 4 Tic-Tac-Toe .h"
        ../Grouped_Games/menu.cpp
        ../Grouped_Games/menu.cpp
)
