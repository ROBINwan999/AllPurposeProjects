cmake_minimum_required(VERSION 3.21)
project(Employee_Management_System)

set(CMAKE_CXX_STANDARD 14)

add_executable(Employee_Management_System main.cpp workerManager.cpp workerManager.h worker.h employee.cpp employee.h manager.cpp manager.h boss.cpp boss.h)
