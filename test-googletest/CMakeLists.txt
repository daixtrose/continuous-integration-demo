cmake_minimum_required(VERSION 3.2.2) 

include(CTest)

################################################################################
# Import Google Test Framework
################################################################################

include(../cmake-helper/DownloadProject/DownloadProject.cmake)
download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             master
                 UPDATE_DISCONNECTED 1
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)

################################################################################
# Define Unit Tests
################################################################################

include_directories(../libs/arithmetics/include)

find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(some_unit_test_using_gtest 
    test_main.cpp
    some_unit_test.cpp
    another_unit_test.cpp)

target_link_libraries(some_unit_test_using_gtest 
    arithmetics
    gtest 
    gmock_main
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
)

add_test(NAME some_unit_test_using_gtest COMMAND some_unit_test_using_gtest)


