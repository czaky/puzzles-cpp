#include "trees.h"

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <unordered_set>
#include <vector>

namespace puzzles {
namespace trees {

struct Node {
  int value;
  Node* left;
  Node* right;

  explicit Node(int value) : value(value){};
};

// Node* make(const std::vector<int>& in) { auto it = in.begin(); }

struct InOrderNodeIterator {
  using iterator_category = std::input_iterator_tag;
  using difference_type = std::ptrdiff_t;
  using value_type = Node*;

  InOrderNodeIterator(Node* t) : _ptr(t) { ++(*this); };

  Node* operator*() { return _ret; }

  explicit operator bool() const { return _ret != nullptr; }

  // Prefix increment
  InOrderNodeIterator& operator++() {
    while (_ptr) {
      _stack.push_back(_ptr);
      _ptr = _ptr->left;
    }
    if (!_stack.empty()) {
      _ret = _stack.back();
      _stack.pop_back();
      _ptr = _ret->right;
    } else {
      _ret = nullptr;
    }
    return *this;
  }

private:
  std::vector<Node*> _stack;
  Node* _ptr;
  Node* _ret;
};

std::vector<int> in_order(Node* t) {
  std::vector<int> r;
  InOrderNodeIterator it(t);
  while (it) {
    r.push_back((*it)->value);
    ++it;
  }
  return r;
}

Node* in_order_double_linked_list(Node* root) {
  if (!root)
    return nullptr;
  InOrderNodeIterator it(root);
  Node* head = *it;
  Node* tail = head;

  while (++it) {
    tail->right = *it;
    tail->right->left = tail;
    tail = tail->right;
  }
  tail->right = nullptr;

  return head;
}

typedef std::pair<Node*, Node*> Range;

/**
 * @brief Helper function for the recursive in_order_double_linked_list.
 *
 * @param root - root node of the tree
 * @return Range - starting and ending node of the resulting list.
 */
Range in_order_double_linked_list_range(Node* root) {
  Node* start = root;
  Node* end = root;
  if (root->left) {
    Range left = in_order_double_linked_list_range(root->left);
    root->left = left.second;
    left.second->right = root;
    start = left.first;
  }
  if (root->right) {
    Range right = in_order_double_linked_list_range(root->right);
    root->right = right.first;
    right.first->left = root;
    end = right.second;
  }

  return {start, end};
}

/**
 * @brief Return a double linked list out of binary tree.
 *
 * This is a recursive operation here.
 *
 * @param root - top of the binary tree.
 * @return Node* - the head of the double linked list.
 */
Node* in_order_double_linked_list_rec(Node* root) {
  return root ? in_order_double_linked_list_range(root).first : root;
}

} // namespace trees
} // namespace puzzles
