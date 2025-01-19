#include "sets.h"

#include <algorithm>
#include <unordered_set>
#include <vector>

namespace puzzles {
namespace sets {

int union_size(const std::vector<int> &a, const std::vector<int> &b) {
  std::unordered_set<int> u(a.begin(), a.end());
  u.insert(b.begin(), b.end());
  return u.size();
}

} // namespace sets
} // namespace puzzles
