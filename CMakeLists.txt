cmake_minimum_required(VERSION 3.30)
project(cpp_hw)

set(CMAKE_CXX_STANDARD 20)

add_executable(task_1
        "task 1/task_1.cpp"
        "task 1/User.cpp"
        "task 1/User.h"
        "task 1/Group.cpp"
        "task 1/Group.h"
        "task 1/Observer.cpp"
        "task 1/Observer.h")

add_executable(task_2
        "task 2/task_2.cpp"
        "task 2/TypeList.hpp")

add_executable(task_3
        "task 3/task_3.cpp"
        "task 3/TypeMap.cpp"
        "task 3/TypeMap.h")
