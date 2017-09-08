# Use GNUInstallDirs to install libraries into correct locations on all platforms.
include(GNUInstallDirs)

add_executable (${CMAKE_PROJECT_NAME}
    main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}
    arithmetics)

INSTALL(TARGETS ${CMAKE_PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})