#include "arithmetics.hpp"

#include "catch.hpp"

SCENARIO("integers can be added", "[integer arithmetics]")
{
  GIVEN("2 integers")
  {
    WHEN("add is called")
    {
      THEN("the result is the sum of both")
      {
        REQUIRE(2 == arithmetics::add(1, 1));
      }
    }
    WHEN("add_buggy is called")
    {
      THEN("the result is the sum of both")
      {
        REQUIRE(2 == arithmetics::add_buggy(1, 1));
      }
    }
  }
}