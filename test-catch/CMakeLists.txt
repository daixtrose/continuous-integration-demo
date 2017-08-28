cmake_minimum_required(VERSION 3.2.2) 

include(CTest)

################################################################################
# Import Catch Test Framework 
################################################################################

include(../cmake-helper/DownloadProject/DownloadProject.cmake)
download_project(PROJ               catch
                 GIT_REPOSITORY      https://github.com/philsquared/Catch
                 GIT_TAG             master
                 UPDATE_DISCONNECTED 1
)

add_custom_command(
  		OUTPUT ${THIRD_PARTY_DIR}/catch
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${Catch_SOURCE_DIR}/single_include/catch.hpp
                ${PROJECT_SOURCE_DIR}/test)

set(CATCH_INCLUDE_DIR ${catch_SOURCE_DIR}/single_include CACHE INTERNAL "Path to include folder for Catch")
include_directories(${CATCH_INCLUDE_DIR})


################################################################################
# Define Unit Tests  
################################################################################


include_directories(../include)

add_executable(some_unit_test_using_catch 
    test_main.cpp
    ../src/arithmetics.cpp
    some_unit_test.cpp
    another_unit_test.cpp)

add_test(NAME some_unit_test_using_catch COMMAND some_unit_test_using_catch)



