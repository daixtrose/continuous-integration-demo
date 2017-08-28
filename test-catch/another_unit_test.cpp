#include "catch.hpp"

TEST_CASE("Test1", "[unit]") {
    int a = 1;
    int b = 1;
    REQUIRE(a == b);
}