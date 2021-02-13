#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <algorithm>
#include <unordered_set>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        if (head == nullptr) {
            return head;
        }

        while (head != nullptr && head->val == val) {
            head = head->next;
        }

        ListNode *ptr = head;
        while (ptr != nullptr && ptr->next != nullptr) {
            if (ptr->next->val == val) {
                ptr->next = ptr->next->next;
            } else {
                ptr = ptr->next;
            }
        }

        return head;
    }
};

} // namespace wb

#endif
