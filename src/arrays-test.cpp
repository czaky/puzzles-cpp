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

std::vector<int> _sort012(const std::vector<int>& in) {
  std::vector<int> out(in);
  sort012(out);
  return out;
}

TEST(ArraysTests, sort012) {
  EXPECT_THAT(_sort012({1, 2, 0, 1}), ElementsAre(0, 1, 1, 2));
  EXPECT_THAT(_sort012({2, 2, 1, 0}), ElementsAre(0, 1, 2, 2));


  EXPECT_THAT(_sort012({0, 0, 0, 0}), ElementsAre(0, 0, 0, 0));
  EXPECT_THAT(_sort012({2, 2, 2, 2}), ElementsAre(2, 2, 2, 2));


  EXPECT_THAT(_sort012({1, 0}), ElementsAre(0, 1));
  EXPECT_THAT(_sort012({2}), ElementsAre(2));
  EXPECT_THAT(_sort012({}), ElementsAre());
}


std::vector<int> _sort_dutch_flag(const std::vector<int>& in) {
  std::vector<int> out(in);
  sort_dutch_flag(out);
  return out;
}

TEST(ArraysTests, sort_dutch_flag) {
  EXPECT_THAT(_sort_dutch_flag({1, 2, 0, 1}), ElementsAre(0, 1, 1, 2));
  EXPECT_THAT(_sort_dutch_flag({2, 2, 1, 0}), ElementsAre(0, 1, 2, 2));


  EXPECT_THAT(_sort_dutch_flag({0, 0, 0, 0}), ElementsAre(0, 0, 0, 0));
  EXPECT_THAT(_sort_dutch_flag({2, 2, 2, 2}), ElementsAre(2, 2, 2, 2));


  EXPECT_THAT(_sort_dutch_flag({1, 0}), ElementsAre(0, 1));
  EXPECT_THAT(_sort_dutch_flag({2}), ElementsAre(2));
  EXPECT_THAT(_sort_dutch_flag({}), ElementsAre());
}

}  // namespace arrays
}  // namespace puzzles
