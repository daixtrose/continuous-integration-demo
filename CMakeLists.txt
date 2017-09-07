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
# Library search path (see https://cmake.org/Wiki/CMake_RPATH_handling)

# The trick is that setting these variables here is partially ignored 
# unless(!) you use
#
#    install(TARGETS ${CMAKE_PROJECT_NAME}
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib)
#
# to declare what you want to isntall, e.g. in subfolders. If you use 
#
#    install (PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME} DESTINATION bin)
#
# you are definitely lost because then either the local version or the installed
# version has the wrong RPATH settings, because the packaging skips RPATH manipulation.

# use, i.e. don't skip the full RPATH for the build tree
SET(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_SKIP_RPATH FALSE)

# when building, don't use the install RPATH already
# (but later on when installing)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 

# Make RPATH in installed programs relative to executable, so it is relocatable
# This could also be 
#     set(CMAKE_INSTALL_RPATH "$ORIGIN:$ORIGIN/../lib")
# Note that
#     set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
# did not work for me for Debian packages, but ORIGIN is the cleanest approach (IMHO)
set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
# Note: I do not see the effect of this varibale
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


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