cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

add_library(list library/list/list.c)

add_executable(task_3.2 homework_3/task_2.c)
target_link_libraries(task_3.2 list)
add_executable(task_2.1 homework_2/task_1.c)
add_executable(task_2.3 homework_2/task_3.c)
