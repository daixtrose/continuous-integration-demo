cmake_minimum_required(VERSION 3.2.2) 

# target_link_libraries(travis_demo LINK_PUBLIC somelibname ${CMAKE_THREAD_LIBS_INIT})

include_directories(../include)

add_executable (travis_demo 
    main.cpp 
	arithmetics.cpp)
