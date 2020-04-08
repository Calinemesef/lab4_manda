cmake_minimum_required(VERSION 3.15)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab4
        main.cpp
        Medikament.cpp
        Medikament.h
        Repository.cpp
        Repository.h UI.cpp Controller.h Controller.cpp UI.h Tests.cpp Tests.h)
