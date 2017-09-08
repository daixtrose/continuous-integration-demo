cmake_minimum_required(VERSION 3.2.2)
# partially inspired by https://rix0r.nl/blog/2015/08/13/cmake-guide/

project(arithmetics VERSION 0.0.1 LANGUAGES CXX)

# Use GNUInstallDirs to install libraries into correct locations on all platforms.
include(GNUInstallDirs)

################################################################################
# Add the library

add_library(arithmetics 
    src/arithmetics.cpp)
    
target_include_directories(arithmetics PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # for headers when building
    $<INSTALL_INTERFACE:include/arithmetics> # for client in install mode
    PRIVATE src
    )

message ("===> ${CMAKE_INSTALL_LIBDIR} = " ${CMAKE_INSTALL_LIBDIR})

install(TARGETS arithmetics EXPORT arithmetics  
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/arithmetics)

# This makes the project importable from the install directory
# Put config file in per-project dir (name MUST match), can also
# just go into 'cmake'.
install(EXPORT arithmetics DESTINATION share/arithmetics/cmake)

# This makes the project importable from the build directory
export(TARGETS arithmetics FILE arithmetics.cmake )



