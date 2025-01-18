#ifndef PUZZLES_SEARCH_H
#define PUZZLES_SEARCH_H

#include<vector>

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
int binary_search(const std::vector<int>& a, int k);

}  // namespace search
}  // namespace puzzles

#endif  // PUZZLES_SEARCH_H
