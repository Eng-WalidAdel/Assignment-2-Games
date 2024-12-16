cmake_minimum_required(VERSION 3.27)
project(Assignment_Demo)

set(CMAKE_CXX_STANDARD 14)

include_directories("C:/Secondyear_firstsem/Assignment_2/Task_2_/group/Assignment Demo")

add_executable(Assignment_Demo
        3x3X_O.h
        BoardGame_Classes.h
#        main.cpp
        menu.cpp
        MinMaxPlayer.h
#        P_Tic_Tac_Toe.cpp
        Pyramid_Tic_Tac_Toe.h
        Word_Tic_Tc_Toe.h
        Connect_Four.h
        Numerical_Tic-Tac-Toe.h
        "4 x 4 Tic-Tac-Toe.h")
