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
    ListNode *reverseList(ListNode *head) {
        ListNode *ptr = head;
        ListNode *prev_ptr = nullptr;

        while (ptr != nullptr) {
            ListNode *next_ptr = ptr->next;
            ptr->next = prev_ptr;
            prev_ptr = ptr;
            ptr = next_ptr;
        }

        return prev_ptr;
    }
};

} // namespace wb

#endif
