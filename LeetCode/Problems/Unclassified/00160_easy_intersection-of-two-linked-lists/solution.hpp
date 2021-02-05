#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <algorithm>
#include <climits>
#include <stack>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr_a = headA;
        ListNode *ptr_b = headB;

        int length_a = this->calculate_list_length(headA);
        int length_b = this->calculate_list_length(headB);

        if (length_a > length_b) {
            for (int i = 0; i < length_a - length_b; i++) {
                ptr_a = ptr_a->next;
            }
        } else {
            for (int i = 0; i < length_b - length_a; i++) {
                ptr_b = ptr_b->next;
            }
        }

        while (ptr_a != NULL) {
            if (ptr_a == ptr_b) {
                return ptr_a;
            }

            ptr_a = ptr_a->next;
            ptr_b = ptr_b->next;
        }

        return NULL;
    }

  private:
    int calculate_list_length(ListNode *head) {
        int length = 0;

        while (head != NULL) {
            head = head->next;
            length++;
        }

        return length;
    }
};

} // namespace wb

#endif
