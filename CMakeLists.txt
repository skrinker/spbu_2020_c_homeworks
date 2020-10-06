
cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(libraries
    library/commonUtils/numericOperations.c
    library/commonUtils/intArrayOperations.c
)

add_library(commonUtils ${libraries})

add_executable(task_1.5 homework_1/task_5.c)

target_link_libraries(task_1.5 commonUtils)