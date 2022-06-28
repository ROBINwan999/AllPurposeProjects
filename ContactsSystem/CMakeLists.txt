cmake_minimum_required(VERSION 3.22)
project(ContactsSystem)

set(CMAKE_CXX_STANDARD 23)

add_executable(ContactsSystem main.cpp Contact.cpp Contact.h Address.cpp Address.h ContactManager.cpp ContactManager.h)
