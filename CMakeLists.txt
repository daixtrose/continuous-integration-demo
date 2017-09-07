cmake_minimum_required(VERSION 3.2.2) 
project(continuous-integration-demo C CXX)

set(MAJOR_VERSION 1)
set(MINOR_VERSION 0)
set(PATCH_VERSION 0)

################################################################################
# C++ standard settings
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_VERBOSE_MAKEFILE ON)

################################################################################
# Diverse variabales

################################################################################
# Packaging configuration

# Debian installer prefix propagated to CMakeCPackConfig
set(DEB_INSTALL_PREFIX "/opt/${PROJECT_NAME}-${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}")

configure_file(CMakeCPackConfig.cmake.in CMakeCPackConfig.cmake @ONLY)

################################################################################
# Library search path, see https://cmake.org/Wiki/CMake_RPATH_handling

# use, i.e. don't skip the full RPATH for the build tree
SET(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_SKIP_RPATH FALSE)

# when building, don't use the install RPATH already
# (but later on when installing)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE) 
SET(CMAKE_INSTALL_RPATH "$ORIGIN;$ORIGIN/../lib")

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)




message("==> CMAKE_INSTALL_RPATH = " ${CMAKE_INSTALL_RPATH})

# the RPATH to be used when installing, but only if it's not a system directory
#LIST(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "$(prefix)/../lib" isSystemDir)
#IF("${isSystemDir}" STREQUAL "-1")
#    SET(CMAKE_INSTALL_RPATH "${CPACK_INSTALL_PREFIX}/lib")
#    message("==> CMAKE_INSTALL_RPATH = " ${CMAKE_INSTALL_RPATH})
#ENDIF("${isSystemDir}" STREQUAL "-1")


################################################################################
# Add Executable
add_subdirectory(libs/arithmetics)
add_subdirectory(src)

################################################################################
enable_testing()

################################################################################
# Build test dependencies for Catch and Gtest.
add_subdirectory(test-catch)
add_subdirectory(test-googletest)

include(${CMAKE_SOURCE_DIR}/CMakeCPack.cmake)

################################################################################
# Additional installation files (see also install directives in subdirectories)
install (FILES ${CMAKE_SOURCE_DIR}/README.md DESTINATION doc)


# https://cmake.org/Wiki/CMake/Tutorials/How_to_create_a_ProjectConfig.cmake_file