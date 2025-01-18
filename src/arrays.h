#ifndef PUZZLES_ARRAYS_H
#define PUZZLES_ARRAYS_H

#include <vector>

namespace puzzles {
namespace arrays {

int second_largest(const std::vector<int> &arr);

std::vector<int> leaders(const std::vector<int> &a);

void sort012(std::vector<int> &a);

void sort_dutch_flag(std::vector<int> &a);

std::vector<int> missing_and_repeating(std::vector<int> &a);

} // namespace arrays
} // namespace puzzles

#endif // PUZZLES_ARRAYS_H
