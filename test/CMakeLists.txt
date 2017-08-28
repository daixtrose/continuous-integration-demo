cmake_minimum_required(VERSION 3.2.2) 

include(CTest)

include(../cmake-helper/DownloadProject/DownloadProject.cmake)
download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             master
                 UPDATE_DISCONNECTED 1}
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

include_directories(../include)

add_executable(some_unit_test 
    some_unit_test.cpp
    ../src/arithmetics.cpp)
target_link_libraries(some_unit_test gtest gmock_main)

add_test(NAME some_unit_test COMMAND some_unit_test)


