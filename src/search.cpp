#include "search.h"

#include <functional>
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

std::vector<std::string> find_paths(const std::vector<std::vector<int>> &maze) {
  const int m = maze.size();
  const int n = maze[0].size();

  std::vector<char> path;
  std::vector<std::string> paths;
  std::vector<std::vector<bool>> v(m, std::vector<bool>(n, 0));

  std::function<void(char, int, int)> dfs = [&](char d, int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m || maze[y][x] == 0 || v[y][x])
      return;
    path.push_back(d);
    if (x == n - 1 && y == m - 1) {
      paths.push_back(std::string(path.begin(), path.end()));
    } else {
      v[y][x] = 1;
      dfs('U', x, y - 1);
      dfs('D', x, y + 1);
      dfs('L', x - 1, y);
      dfs('R', x + 1, y);
      v[y][x] = 0;
    }
    path.pop_back();
  };

  v[0][0] = 1;
  dfs('D', 0, 1);
  dfs('R', 1, 0);

  return paths;
}

} // namespace search
} // namespace puzzles
