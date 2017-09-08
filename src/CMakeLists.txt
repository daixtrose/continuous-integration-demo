add_executable (${CMAKE_PROJECT_NAME}
    main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}
    arithmetics)

INSTALL(TARGETS ${CMAKE_PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)