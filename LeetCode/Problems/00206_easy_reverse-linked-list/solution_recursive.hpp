#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <cmath>

#include <algorithm>
#include <stack>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    ListNode *_reverse_list(ListNode *node) {
        if (node->next == nullptr) {
            return node;
        }

        ListNode *head = _reverse_list(node->next);
        node->next->next = node;
        return head;
    }

    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }

        ListNode *end = _reverse_list(head);
        head->next = nullptr;

        return end;
    }
};

} // namespace wb

#endif
