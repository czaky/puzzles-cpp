#include "arrays.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"


namespace puzzles {
namespace arrays {

using namespace ::testing;

TEST(ArraysTests, SecondLargest) {
  EXPECT_EQ(second_largest({1, 2, 3, 4}), 3);
  EXPECT_EQ(second_largest({5, 2, 3, 4}), 4);
  EXPECT_EQ(second_largest({10, 5, 2, 3, 4, 10}), 5);
  EXPECT_EQ(second_largest({10, 5, 10}), 5);
}

TEST(ArraysTests, SecondLargestFail) {
  EXPECT_EQ(second_largest({}), -1);
  EXPECT_EQ(second_largest({5}), -1);
  EXPECT_EQ(second_largest({10, 10}), -1);
  EXPECT_EQ(second_largest({10, 10, 10}), -1);
}

TEST(ArraysTests, Leaders) {
  EXPECT_THAT(leaders({1, 2, 3, 4}), ElementsAre(4));
  EXPECT_THAT(leaders({5, 2, 3, 4}), ElementsAre(5, 4));
}


}  // namespace arrays
}  // namespace puzzles
