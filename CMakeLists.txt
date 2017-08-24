cmake_minimum_required(VERSION 3.5.1)
project(TRAVIS_DEMO C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost COMPONENTS system filesystem REQUIRED)

add_subdirectory(src)
add_subdirectory(test)

# target_link_libraries(travis_demo LINK_PUBLIC pigpio ${CMAKE_THREAD_LIBS_INIT})

    
include_directories(include)





