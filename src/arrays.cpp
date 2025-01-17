#include "arrays.h"

#include <vector>

namespace puzzles {
namespace arrays {

/**
 * @brief Return the second largest value from the vector `arr`.
 *
 * @param arr
 * @return int
 */
int second_largest(const std::vector<int>& arr) {
    if (arr.size() < 2) return -1;
    int f = std::max(arr[0], arr[1]);
    int s = std::min(arr[0], arr[1]);
    for (int e : arr) {
        if (f < e) {
            s = f;
            f = e;
        } else if (s < e && e != f) {
            s = e;
        }

    }
    return f == s ? -1 : s;
}

}  // namespace arrays
}  // namespace puzzles
