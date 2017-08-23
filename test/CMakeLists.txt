include(GoogleTest)
add_executable(some_unit_test some_unit_test.cxx)
gtest_add_tests(TARGET      some_unit_test
                TEST_SUFFIX .noArgs
                TEST_LIST   noArgsTests)
gtest_add_tests(TARGET      some_unit_test
                EXTRA_ARGS  --someArg "foo"
                TEST_SUFFIX .withArgs
                TEST_LIST   withArgsTests)
set_tests_properties(${noArgsTests}   PROPERTIES TIMEOUT 10)
set_tests_properties(${withArgsTests} PROPERTIES TIMEOUT 20)