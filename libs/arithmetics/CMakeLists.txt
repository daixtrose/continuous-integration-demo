cmake_minimum_required(VERSION 3.2.2)

include_directories(include)

add_library(arithmetics SHARED 
    src/arithmetics.cpp)

install(TARGETS arithmetics DESTINATION lib)