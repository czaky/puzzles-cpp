#include "geo.h"

#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

namespace puzzles {
namespace geo {

/**
 * @brief return maximum count of `points` visible at `angle_rad`.
 *
 * @param points in cartesian
 * @param angle_rad sweep angle in radians
 * @return int
 */

int max_point_angle_sweep(const std::vector<std::complex<float>> &points,
                          float angle_rad) {
  std::vector<float> rads;
  int near = 0;

  for (auto &p : points) {
    if (std::abs(p) < 1.0) {
      ++near;
    } else {
      float r = std::arg(p);
      rads.push_back(r);
      rads.push_back(r + 2.0 * std::numbers::pi);
    }
  }
  std::sort(rads.begin(), rads.end());
  const int n = rads.size();

  int max = 0; // return value
  int i = 0;
  for (int j = 1; j < n; ++j) {
    while (i < j && rads[j] - rads[i] > angle_rad) {
      i++;
    }
    max = std::max(max, j - i + 1);
  }
  return max + near;
}

} // namespace geo
} // namespace puzzles
