#ifndef PUZZLES_LISTS_H
#define PUZZLES_LISTS_H

#include <vector>

namespace puzzles {
namespace lists {

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* make_list(const std::vector<int>& v);

std::vector<ListNode*> make_lists(const std::vector<std::vector<int>>& vs);

ListNode* mergeKLists(std::vector<ListNode*>& lists);

int len(ListNode* l);

} // namespace lists
} // namespace puzzles

#endif // PUZZLES_LISTS_H
