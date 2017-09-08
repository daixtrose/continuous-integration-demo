cmake_minimum_required(VERSION 3.2.2)
# partially inspired by https://rix0r.nl/blog/2015/08/13/cmake-guide/

set(LIBRARY_NAME arithmetics)

project(${LIBRARY_NAME} VERSION 0.0.1 LANGUAGES CXX)

# Use GNUInstallDirs to install libraries into correct locations on all platforms.
include(GNUInstallDirs)

################################################################################
# Add the library

add_library(${LIBRARY_NAME} 
    src/arithmetics.cpp)
    
target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # for headers when building
    $<INSTALL_INTERFACE:include/${LIBRARY_NAME}> # for client in install mode
    PRIVATE src
    )

message ("===> ${CMAKE_INSTALL_LIBDIR} = " ${CMAKE_INSTALL_LIBDIR})

install(TARGETS ${LIBRARY_NAME} EXPORT ${LIBRARY_NAME}  
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR})  

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${LIBRARY_NAME})

# This makes the project importable from the install directory
# Put config file in per-project dir (name MUST match), can also
# just go into 'cmake'.
install(EXPORT ${LIBRARY_NAME} DESTINATION share/${LIBRARY_NAME}/cmake)

# This makes the project importable from the build directory
export(TARGETS ${LIBRARY_NAME} FILE ${LIBRARY_NAME}.cmake )



