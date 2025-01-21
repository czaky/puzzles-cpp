#ifndef PUZZLES_HEAPS_H
#define PUZZLES_HEAPS_H

#include <queue>
#include <vector>

namespace puzzles {
namespace heaps {

template <typename T> class MedianFilter {
  std::priority_queue<T> l;
  std::priority_queue<T> h;

public:
  MedianFilter() = default;

  void add(const T &n) {
    if (l.size() > h.size()) {
      if (n >= l.top()) {
        h.push(-n);
      } else {
        l.push(n);
        h.push(-l.top());
        l.pop();
      }
    } else if (h.empty() || n <= -h.top()) {
      l.push(n);
    } else {
      h.push(-n);
      l.push(-h.top());
      h.pop();
    }
  }

  double median() const {
    return l.size() == h.size() ? (l.top() - h.top()) / 2.0 : l.top();
  }
};

} // namespace heaps
} // namespace puzzles

#endif // PUZZLES_HEAPS_H
