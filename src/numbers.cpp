#include "numbers.h"

namespace puzzles {
namespace numbers {

int count_digit_divisors(int n) {
  int count = 0;
  int m = n;
  while (n > 0) {
    int d = n % 10;
    count += d && m % d == 0;
    n = n / 10;
  }
  return count;
}

} // namespace numbers
} // namespace puzzles
