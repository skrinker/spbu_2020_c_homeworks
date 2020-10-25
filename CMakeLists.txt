cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

add_library(list library/list/list.c)
add_executable(task_3.1 homework_3/task_1.c)
target_link_libraries(task_3.1 list)
