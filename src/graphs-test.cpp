#include "graphs.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace puzzles {
namespace graphs {

using namespace ::testing;

TEST(GraphsTests, CriticalPoints) {
  std::vector<std::vector<int>> adj = {
      {1},    {0, 2, 5}, {1, 3, 6, 7}, {2, 4, 5},
      {3, 5}, {4, 1, 3}, {2, 7},       {6, 2},
  };
  EXPECT_THAT(critical_points(adj), ElementsAre(1, 2));

  adj = {
      {6, 5, 4}, {8, 5},       {6, 7}, {5},       {8, 0},
      {0, 3, 1}, {0, 8, 7, 2}, {6, 2}, {6, 4, 1},
  };
  EXPECT_THAT(critical_points(adj), ElementsAre(5, 6));

  adj = {
      {1, 2, 3, 6, 8},
      {0, 2, 3, 4, 5, 6},
      {0, 1, 3, 6, 8},
      {0, 1, 2, 4, 6, 8},
      {1, 3, 8},
      {1, 6},
      {0, 1, 2, 3, 5, 7, 8},
      {6},
      {0, 2, 3, 4, 6},
  };
  EXPECT_THAT(critical_points(adj), ElementsAre(6));

  adj = {
      {8, 2, 5, 6}, {8},       {0, 6}, {8, 9},       {8},
      {0, 7},       {0, 9, 2}, {5},    {0, 1, 3, 4}, {3, 6},
  };
  EXPECT_THAT(critical_points(adj), ElementsAre(0, 5, 8));

  adj = {
      {2, 2, 1, 3, 6, 8},
      {3, 4, 2, 5, 5, 3, 0, 6},
      {1, 2, 2, 0, 6, 6, 2, 2, 0, 6, 8, 3},
      {4, 1, 6, 8, 1, 0, 4, 2},
      {3, 1, 8, 3},
      {5, 5, 1, 6, 1, 6},
      {6, 6, 2, 2, 3, 6, 6, 5, 2, 8, 1, 5, 0, 7},
      {6},
      {3, 2, 6, 4, 0},
  };
  EXPECT_THAT(critical_points(adj), ElementsAre(6));
}

} // namespace graphs
} // namespace puzzles
