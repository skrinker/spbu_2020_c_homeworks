cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
)
add_library(library ${SOURCE_LIB})
add_library(matrix library/matrix/matrix.c)

add_executable(test_1.2 test_1/task_1.c)
target_link_libraries(test_1.2)
add_executable(task_1.1 homework_1/task_1.c)
add_executable(task_1.4 homework_1/task_4.c)
