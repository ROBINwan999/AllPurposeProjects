cmake_minimum_required(VERSION 3.21)
project(Speech_Contest_Process_Management_System)

set(CMAKE_CXX_STANDARD 23)

add_executable(Speech_Contest_Process_Management_System main.cpp speechManager.cpp speechManager.h speaker.h)
