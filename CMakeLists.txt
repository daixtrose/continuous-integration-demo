cmake_minimum_required(VERSION 3.2.2) 
project(continuous-integration-demo C CXX)

set(MAJOR_VERSION 1)
set(MINOR_VERSION 0)
set(PATCH_VERSION 0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

################################################################################
# Add Executable
add_subdirectory(src)

################################################################################
enable_testing()

################################################################################
# Build test dependencies for Catch and Gtest.
add_subdirectory(test-catch)
add_subdirectory(test-googletest)

################################################################################
# Packaging configuration
set(CPACK_GENERATOR "DEB" "TGZ")
# - CPack configuration for individual targets 
set(CPACK_PROJECT_CONFIG_FILE ${CMAKE_SOURCE_DIR}/CMakeCPackConfig.cmake)
# - CPack configuration for all targets 
include(${CMAKE_SOURCE_DIR}/CMakeCPack.cmake)
include(CPack)

################################################################################
# Additional installation files (see also install directives in subdirectories)
install (FILES ${CMAKE_SOURCE_DIR}/README.md DESTINATION doc)



