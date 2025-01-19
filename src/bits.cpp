#include "bits.h"

#include <algorithm>
#include <unordered_set>
#include <vector>

namespace puzzles {
namespace bits {

bool is_power_of_2(int n) { return n > 0 && !(n & (n - 1)); }

} // namespace bits
} // namespace puzzles
