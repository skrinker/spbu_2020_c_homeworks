cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

add_library(stack library/stack/stack.c)
add_library(numericOperations library/commonUtils/numericOperations.c)
add_library(stringOperations library/stringUtils/stringOperations.c)

add_executable(task_4.1 homework_4/task_1.c)
target_link_libraries(task_4.1 stack stringOperations numericOperations)

