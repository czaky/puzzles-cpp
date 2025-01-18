#include "search.h"

#include <vector>

namespace puzzles {
namespace search {

/**
 * @brief search for `k` in sorted vector `a`.
 *
 * @param a a sorted vector of integers;
 * @param k an integer to search for.
 *
 * @return the index of k or -1.
 */
int binary_search(const std::vector<int> &a, int k) {
  int l = 0;
  int h = a.size() - 1;
  int m = (l + h) >> 1;
  while (l < h) {
    if (a[m] < k) {
      l = m + 1;
    } else {
      h = m;
    }
    m = (l + h) >> 1;
  }
  return a[m] == k ? m : -1;
}

} // namespace search
} // namespace puzzles
