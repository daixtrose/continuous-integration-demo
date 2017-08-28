#include "arithmetics.hpp"
#include "gtest/gtest.h"

TEST(TestAdd, PerformsAdditionOnTwoIntegers) {
  EXPECT_EQ(2, arithmetics::add(1, 1));
}

TEST(TestAdd, PerformsAdditionOnTwoIntegers_2) {
  EXPECT_EQ(2, arithmetics::add_buggy(1, 1));
}

