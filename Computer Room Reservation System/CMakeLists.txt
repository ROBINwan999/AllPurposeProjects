cmake_minimum_required(VERSION 3.21)
project(Computer_Room_Reservation_System)

set(CMAKE_CXX_STANDARD 23)

add_executable(Computer_Room_Reservation_System main.cpp identity.h student.cpp student.h teacher.cpp teacher.h manager.cpp manager.h globalFile.h computerRoom.h orderFile.cpp orderFile.h)
