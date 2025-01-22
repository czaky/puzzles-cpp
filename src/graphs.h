#ifndef PUZZLES_GRAPHS_H
#define PUZZLES_GRAPHS_H

#include <set>
#include <vector>

namespace puzzles {
namespace graphs {

std::set<int> critical_points(const std::vector<std::vector<int>> &a);

std::set<std::pair<int, int>>
critical_connections(const std::vector<std::vector<int>>& a);

} // namespace graphs
} // namespace puzzles

#endif // PUZZLES_GRAPHS_H
