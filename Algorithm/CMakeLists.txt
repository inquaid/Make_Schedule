cmake_minimum_required(VERSION 3.18)
project(Schedule_Management)

set(CMAKE_CXX_STANDARD 17)

add_executable(Schedule_Management
        src/Teacher.cpp
        src/Course.cpp
        src/TimeSlot.cpp
        src/Schedule.cpp
        src/main.cpp
)

target_include_directories(Schedule_Management
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)
