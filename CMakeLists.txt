cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

add_library(library library/commonUtils/numericOperations.c)

add_executable(task_2.2 homework_2/task_2.c)
target_link_libraries(task_2.2 library)
