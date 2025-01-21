#include "geo.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace puzzles {
namespace geo {

using namespace ::testing;
using namespace std::numbers;

constexpr float deg = pi / 180.0;

TEST(GeoTests, max_point_angle_sweep) {
  EXPECT_EQ(max_point_angle_sweep({{0, -1}, {1, 0}}, 13 * deg), 1);
  EXPECT_EQ(max_point_angle_sweep({{1, 0}, {1, 1}, {2, 2}}, 90 * deg), 3);
  EXPECT_EQ(max_point_angle_sweep({{1, 0}, {1, 1}, {2, 3}, {0, 0}}, 90 * deg),
            4);
}

} // namespace geo
} // namespace puzzles
