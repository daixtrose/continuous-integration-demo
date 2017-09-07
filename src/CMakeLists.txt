cmake_minimum_required(VERSION 3.2.2) 

# target_link_libraries(travis_demo LINK_PUBLIC somelibname ${CMAKE_THREAD_LIBS_INIT})

include_directories(../libs/arithmetics/include)

add_executable (${CMAKE_PROJECT_NAME}
    main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}
    arithmetics)

install (PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME} DESTINATION bin)
    