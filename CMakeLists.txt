cmake_minimum_required(VERSION 3.25)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

add_executable(TicTacToe main.cpp Board.cpp Board.h PositionNotAvailable.h InvalidMove.h)
