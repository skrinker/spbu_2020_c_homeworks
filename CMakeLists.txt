cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
)
set(CMAKE_C_COMPILER_AR
    /bin/lldb
)
add_library(library ${SOURCE_LIB})

add_link_options(-fsanitize=address)
add_compile_options(-fsanitize=address -g)

add_executable(task_3.1 homework_3/main.c)
