
cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)
set(CMAKE_C_STANDARD 11)

set(libraries
    library/commonUtils/numericOperations.c
    library/commonUtils/intArrayOperations.c
    library/commonUtils/stringOperations.c
)

add_library(libraries ${libraries})
add_library(list library/list/list.c)
add_library(stack library/stack/stack.c)
add_library(bst library/bst/bst.c)
add_library(bstNode library/bst/bstNode.c)
add_library(dfs library/dfa/dfa.c)
add_library(io library/IO/io.c)
add_library(graph library/graph/graph.c)
add_library(avl library/avl/avl.c)
add_library(avlNode library/avl/avlNode.c)
add_library(hashTable library/hashTable/hashTable.c)
add_library(doubleLinkedList library/doubleLinkedList/list.c)
add_library(priorityQueue library/priorityQueue/queue.c)

add_executable(test_3.2.1 test_3/task_2.c)
target_link_libraries(test_3.2.1 priorityQueue)
add_executable(test_3.1 test_3/task_1.c)
target_link_libraries(test_3.1 hashTable libraries)
add_executable(test_2.3.1 test_2/task_3.c)
target_link_libraries(test_2.3.1 graph)
add_executable(task_8.1 homework_8/task_1.c)
target_link_libraries(task_8.1 dfs libraries)
add_executable(test_2.2.1 test_2/task_2.c)
target_link_libraries(test_2.2.1 io libraries)
add_executable(test_1.1.1 test_1/task_1.c)
target_link_libraries(test_1.1.1 doubleLinkedList)
add_executable(task_7.1 homework_7/task_1.c)
target_link_libraries(task_7.1 graph)
add_executable(task_6.1 homework_6/task_1.c)
target_link_libraries(task_6.1 hashTable io libraries)
add_executable(task_5.2 homework_5/task_2.c)
target_link_libraries(task_5.2 avl avlNode libraries)
add_executable(task_5.1 homework_5/task_1.c)
target_link_libraries(task_5.1 bst bstNode)
add_executable(task_4.3 homework_4/task_3.c)
add_executable(task_4.2 homework_4/task_2.c)
add_executable(task_4.1 homework_4/task_1.c)
target_link_libraries(task_4.1 libraries stack)
add_executable(task_3.2 homework_3/task_2.c)
target_link_libraries(task_3.2 list)
add_executable(task_3.1 homework_3/task_1.c)
target_link_libraries(task_3.1 list)
add_executable(task_2.5 homework_2/task_5.c)
add_executable(task_2.4 homework_2/task_4.c)
target_link_libraries(task_2.4 libraries)
add_executable(task_2.3 homework_2/task_3.c)
add_executable(task_2.2 homework_2/task_2.c)
target_link_libraries(task_2.2 libraries)
add_executable(task_2.1 homework_2/task_1.c)
target_link_libraries(task_2.1 libraries)
add_executable(task_1.5 homework_1/task_5.c)
target_link_libraries(task_1.5 libraries)
add_executable(task_1.4 homework_1/task_4.c)
target_link_libraries(task_1.4 libraries)
add_executable(task_1.3 homework_1/task_3.c)
target_link_libraries(task_1.3 libraries)
add_executable(task_1.2 homework_1/task_2.c)
target_link_libraries(task_1.2 libraries)
add_executable(task_1.1 homework_1/task_1.c)
