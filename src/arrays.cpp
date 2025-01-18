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

/**
 * @brief Given an array of 0, 1, and 2, sort it in ascending order.
 *
 * The approach here will count the occurrence of each
 * and will then fill the array with corresponding counts.
 *
 * @param a vector of integers
 */
void sort012(std::vector<int>& a) {
    int zeros = 0;
    int ones = 0;
    for (int e: a) {
        if (e == 0) ++zeros;
        if (e == 1) ++ones;
    }
    std::fill(a.begin(), a.begin() + zeros, 0);
    std::fill(a.begin() + zeros, a.begin() + zeros + ones, 1);
    std::fill(a.begin() + zeros + ones, a.end(), 2);
}

/**
 * @brief Given an array of 0, 1, and 2, sort it in ascending order.
 *
 * The approach here uses two pointers `l`, and `h` to demarcate
 * the line between zeros and ones, and the line between ones and twos.
 *
 *
 * @param a vector of integers
 */
void sort_dutch_flag(std::vector<int>& a) {
        int l = 0;
        int h = a.size();

        for (int m = 0; m < h; m++) {
            while (a[m] == 2 && m < h) std::swap(a[m], a[--h]);
            if (a[m] == 0) std::swap(a[l++], a[m]);
        }
}

std::vector<int> missing_and_repeating(std::vector<int>& a) {
    int n = a.size();
    int duplicate = -1;
    for (int i=0; i < n; ++i) {
        int e = abs(a[i]);
        if (a[e - 1] < 0) {
            duplicate = e;
        } else {
            a[e - 1] = -a[e - 1];
        }
    }
    int missing = -1;
    for (int i = 0; i<n; ++i) {
      if (a[i] >= 0) {
        missing = i + 1;
        break;
      }
    }

    return {missing, duplicate};
}

}  // namespace arrays
}  // namespace puzzles
