cmake_minimum_required(VERSION 3.22)
project(StudentMarkAnalysisSystem)

set(CMAKE_CXX_STANDARD 23)

add_executable(StudentMarkAnalysisSystem main.cpp Student.cpp Student.h StudentManager.cpp StudentManager.h)
