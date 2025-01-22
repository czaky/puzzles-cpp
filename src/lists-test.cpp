#include "lists.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace puzzles {
namespace lists {

using namespace ::testing;

TEST(ListsTests, make_lists) {
  auto lists = make_lists({{}});
  EXPECT_EQ(lists.size(), 1);
  EXPECT_EQ(lists[0], nullptr);
}

TEST(ListsTests, make_lists_1) {
  auto lists = make_lists({{1}});
  EXPECT_EQ(lists.size(), 1);
  EXPECT_NE(lists[0], nullptr);
  EXPECT_EQ(lists[0]->val, 1);
}

TEST(ListsTests, make_lists_2) {
  auto lists = make_lists({{1, 2}, {3, 4}});
  EXPECT_EQ(lists.size(), 2);
  EXPECT_NE(lists[0], nullptr);
  EXPECT_EQ(lists[0]->val, 1);
  EXPECT_NE(lists[1], nullptr);
  EXPECT_EQ(lists[1]->val, 3);
}

TEST(ListsTests, mergeKLists_2) {
  auto lists = make_lists({{1, 2}, {3, 4}});
  EXPECT_EQ(lists.size(), 2);
  auto m = mergeKLists(lists);
  EXPECT_EQ(len(m), 4);
  EXPECT_EQ(m->val, 1);
  EXPECT_EQ(m->next->val, 2);
  EXPECT_EQ(m->next->next->val, 3);
  EXPECT_EQ(m->next->next->next->val, 4);
}

TEST(ListsTests, mergeKLists_empty_one) {
  auto lists = make_lists({{}});
  EXPECT_EQ(lists.size(), 1);
  EXPECT_EQ(len(mergeKLists(lists)), 0);
}

TEST(ListsTests, mergeKLists_empty_none) {
  auto lists = make_lists({});
  EXPECT_EQ(lists.size(), 0);
  EXPECT_EQ(len(mergeKLists(lists)), 0);
}

} // namespace lists
} // namespace puzzles
