#include "arrays.h"

#include <vector>


int second_largest(std::vector<int> &arr) {
    if (arr.size() < 2) return -1;
    int f = max(arr[0], arr[1]);
    int s = min(arr[0], arr[1]);
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
