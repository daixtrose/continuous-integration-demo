cmake_minimum_required(VERSION 3.2.2) 
project(TRAVIS_DEMO C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

enable_testing()

add_subdirectory(test-catch)

add_subdirectory(test-googletest)





