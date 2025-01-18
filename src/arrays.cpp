#include "arrays.h"

#include <vector>
#include <algorithm>

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

/**
 * @brief Return the leading values to the left
 *
 * A leading value is larger or equal to all values to the right.
 *
 * @param a - vector
 * @return std::vector<int> representing the leading values
 */
std::vector<int> leaders(const std::vector<int>& a) {
    int n = a.size();
    std::vector<int> leaders;
    if (n == 0) return leaders;
    leaders.reserve(n);
    leaders.push_back(a.back());
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= leaders.back()) {
            leaders.push_back(a[i]);
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

}  // namespace arrays
}  // namespace puzzles
