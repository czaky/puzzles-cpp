#include "numbers.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace puzzles {
namespace numbers {

using namespace ::testing;

TEST(SearchTests, binary_search) {
  EXPECT_EQ(count_digit_divisors(12), 2);
  EXPECT_EQ(count_digit_divisors(23), 0);
}

} // namespace numbers
} // namespace puzzles
