#include "bits.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace puzzles {
namespace bits {

using namespace ::testing;

TEST(BitsTests, PowerOf2) {
  EXPECT_TRUE(is_power_of_2(1));
  EXPECT_TRUE(is_power_of_2(2));
  EXPECT_TRUE(is_power_of_2(4));
  EXPECT_TRUE(is_power_of_2(8));
}

TEST(BitsTests, PowerOf2False) {
  EXPECT_FALSE(is_power_of_2(0));
  EXPECT_FALSE(is_power_of_2(-1));
  EXPECT_FALSE(is_power_of_2(3));
  EXPECT_FALSE(is_power_of_2(5));
}

} // namespace bits
} // namespace puzzles
