// This code was stolen from https://github.com/google/googletest/blob/master/googletest/docs/Primer.md and adopted
#include "gtest/gtest.h"

#include <boost/filesystem.hpp>

#include <string>
#include <iostream>
#include <fstream>

class Foo {
public: 
    int Bar(const std::string & input_filepath, const std::string output_filepath)
    {
        std::cout << "I: " << input_filepath << std::endl;
        std::cout << "O: " << output_filepath << std::endl;
     
        if (boost::filesystem::exists(input_filepath)
            &&
            boost::filesystem::exists(output_filepath))
        {
            return 0;
        }
     
        return 1;
    }
};

namespace {

/* 
// In C++17, you can use string_view:
using namespace std::string_view_literals;
constexpr std::string_view sv = "hello, world"sv;
*/ 
static constexpr auto input_filepath = "myinputfile.dat";
static constexpr auto output_filepath = "myoutputfile.dat";
    
// The fixture for testing class Foo.
class FooTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  FooTest() {
    // You can do set-up work for each test here.
    std::ofstream input_file{input_filepath};
    input_file << "Some Test Data";
    std::ofstream output_file{output_filepath};
    input_file << "Some Test Data";
  }

  virtual ~FooTest() {
    try 
    {
      // You can do clean-up work that doesn't throw exceptions here.
      boost::filesystem::remove(input_filepath);
      boost::filesystem::remove(output_filepath);
    } 
    catch (...) 
    {
      std::cerr << "Nothing to remove here." << std::endl;
    } 
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(FooTest, MethodBarDoesAbc) {
  Foo f;
  EXPECT_EQ(0, f.Bar(input_filepath, output_filepath));
}

}  // namespace