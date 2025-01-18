#include "search.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace puzzles {
namespace search {

using namespace ::testing;

TEST(SearchTests, binary_search) {
  EXPECT_EQ(binary_search({1, 2, 3, 4}, 1), 0);
  EXPECT_EQ(binary_search({1, 2, 3, 4}, 3), 2);
  EXPECT_EQ(binary_search({1, 2, 3, 4}, 4), 3);
  EXPECT_EQ(binary_search({5, 6, 70, 80}, 5), 0);
  EXPECT_EQ(binary_search({-3, 0, 20, 100}, -3), 0);
  EXPECT_EQ(binary_search({2, 5, 10}, 20), -1);
  EXPECT_EQ(binary_search({2, 5, 10}, 1), -1);
  EXPECT_EQ(binary_search({2, 5, 10}, 4), -1);
  EXPECT_EQ(binary_search({2, 5, 10}, 7), -1);
}

} // namespace search
} // namespace puzzles
