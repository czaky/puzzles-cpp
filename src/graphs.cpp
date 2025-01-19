#include "graphs.h"

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

namespace puzzles {
namespace graphs {

typedef int32_t int32;

/**
 * @brief return the set of critical points in the graph defined by `a`.
 *
 * A critical point in the graph would partition the graph into two
 * components if it was removed from the graph.
 *
 * The graph is represented by a vector of adjacency vectors for each node.
 *
 * @param a adjacency list for all the nodes from 0 .. N.
 * @return std::set<int> - set of critical points.
 */
std::set<int> critical_points(const std::vector<std::vector<int>> &a) {
  // Using modification of Tarjan's algorithm.
  // Using two stacks s1 and s2.
  // Both stack contain a pair
  std::vector<std::pair<int32, int32>> s1, s2;
  // Using visit time and minimum connection time.
  std::vector<int32> vt, ct;
  vt.resize(a.size());
  ct.resize(a.size());

  int t = 0;
  int root_kids = 0;
  // Add root to seed the stack.
  s1.push_back({-1, 0});
  // Linearize all nodes in DFS order.
  while (!s1.empty()) {
    auto [p, n] = s1.back();
    s1.pop_back();
    // Using visit time > 0 as visited marker.
    if (vt[n]) {
      continue;
    }
    vt[n] = ct[n] = ++t;
    if (p > 0) {
      // Only add non-root children.
      s2.push_back({p, n});
    } else if (p == 0) {
      ++root_kids;
    }
    for (int c : a[n]) {
      if (!vt[c]) {
        s1.push_back({n, c});
      }
    }
  }

  std::set<int> critical;
  // Add root node if it has more children.
  if (root_kids >= 2) {
    critical.insert(0);
  }

  // Only non-root children are on s2.
  // We are adding the parents of the nodes on s2
  // to the critical node list.
  while (!s2.empty()) {
    auto [p, n] = s2.back();
    // std::cout << "p: " << p << " n: " << n << std::endl;
    s2.pop_back();

    // Determine the lowest time each of
    // the non-root adjacent nodes were visited.
    // A smaller vt will indicate an up-link.
    for (int c : a[n]) {
      if (c != p) {
        ct[n] = std::min(ct[n], vt[c]);
      }
    }

    // If this node does not have an uplink earlier in the DFS
    // tree, then the root node is the only node that connects it
    // to the network.
    if (vt[p] <= ct[n]) {
      critical.insert(p);
    }
    // This will be a nop, unless there is an uplink higher.
    ct[p] = std::min(ct[p], ct[n]);
  }

  return critical;
}

} // namespace graphs
} // namespace puzzles
