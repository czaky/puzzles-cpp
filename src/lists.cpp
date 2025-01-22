#include "lists.h"

#include <cassert>
#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>

namespace puzzles {
namespace lists {

ListNode* make_list(const std::vector<int>& v) {
  ListNode* head = nullptr;
  if (!v.empty()) {
    head = new ListNode(v[0]);
    ListNode* tail = head;
    for (int i = 1; i < v.size(); ++i) {
      tail = tail->next = new ListNode(v[i]);
    }
  }
  return head;
}

std::vector<ListNode*> make_lists(const std::vector<std::vector<int>>& vs) {
  std::vector<ListNode*> r(vs.size(), nullptr);
  for (int i = 0; i < vs.size(); ++i) {
    r[i] = make_list(vs[i]);
  }
  return r;
}

int len(ListNode* l) {
  int n = 0;
  while (l != nullptr) {
    ++n;
    l = l->next;
  }
  return n;
}

struct Greater {
  bool operator()(ListNode* a, ListNode* b) const { return a->val > b->val; }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
  // min heap
  std::priority_queue<ListNode*, std::vector<ListNode*>, Greater> pq;

  for (auto list : lists) {
    if (list) {
      pq.push(list);
    }
  }
  if (pq.empty())
    return nullptr;

  ListNode* head = pq.top();
  ListNode* tail = head;

  do {
    pq.pop();
    if (tail->next) {
      pq.push(tail->next);
    }
    tail = tail->next = pq.top();
  } while (!pq.empty());

  tail->next = nullptr;
  return head;
}

} // namespace lists
} // namespace puzzles
