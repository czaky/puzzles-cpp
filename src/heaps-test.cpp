#include "heaps.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace puzzles {
namespace heaps {

using namespace ::testing;

TEST(HeapsTests, MedianFilter) {
  MedianFilter<int> mf;
  mf.add(1);
  EXPECT_EQ(mf.median(), 1);
  mf.add(2);
  EXPECT_EQ(mf.median(), 1.5);
  mf.add(3);
  EXPECT_EQ(mf.median(), 2);
  mf.add(2);
  EXPECT_EQ(mf.median(), 2);
  mf.add(-2);
  EXPECT_EQ(mf.median(), 2);
  mf.add(-1);
  EXPECT_EQ(mf.median(), 1.5);
}

} // namespace heaps
} // namespace puzzles
