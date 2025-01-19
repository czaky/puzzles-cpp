#include "sets.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace puzzles {
namespace sets {

using namespace ::testing;

TEST(SetsTests, UnionSize) {
  EXPECT_EQ(union_size({1, 2, 3, 4}, {1, 2, 3, 4}), 4);
  EXPECT_EQ(union_size({1, 2, 3}, {1, 2, 3, 4}), 4);
  EXPECT_EQ(union_size({1, 2, 3, 4}, {2, 3, 4}), 4);
  EXPECT_EQ(union_size({1, 2}, {3, 4}), 4);
}

} // namespace sets
} // namespace puzzles
