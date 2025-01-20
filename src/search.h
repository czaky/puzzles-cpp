#ifndef PUZZLES_SEARCH_H
#define PUZZLES_SEARCH_H

#include <string>
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
int binary_search(const std::vector<int> &a, int k);

/**
 * @brief find all paths in a maze.
 *
 * Paths are string of letters U, D, R, L.
 *
 * @param maze
 * @return std::vector<std::string>
 */
std::vector<std::string> find_paths(const std::vector<std::vector<int>> &maze);

} // namespace search
} // namespace puzzles

#endif // PUZZLES_SEARCH_H
