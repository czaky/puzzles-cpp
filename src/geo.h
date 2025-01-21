#ifndef PUZZLES_GEO_H
#define PUZZLES_GEO_H

#include <complex>
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
                          float angle_rad);

} // namespace geo
} // namespace puzzles

#endif // PUZZLES_GEO_H
