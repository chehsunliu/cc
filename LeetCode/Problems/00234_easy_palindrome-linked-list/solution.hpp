#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <stack>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  private:
    int calculate_length(ListNode *node) {
        int length = 0;
        while (node != nullptr) {
            node = node->next;
            length++;
        }
        return length;
    }

    ListNode *determine(ListNode *node, int index, int length, bool &is_palindrome) {
        if (index == length / 2 - 1) {
            if (length % 2 == 1 ) {
                is_palindrome &= node->val == node->next->next->val;
                return node->next->next->next;
            } else {
                is_palindrome &= node->val == node->next->val;
                return node->next->next;
            }
        } else {
            ListNode *node2 = determine(node->next, index + 1, length, is_palindrome);
            is_palindrome &= node->val == node2->val;
            return node2->next;
        }
    }

  public:
    bool isPalindrome(ListNode *head) {
        const int length = this->calculate_length(head);
        if (length <= 1) {
            return true;
        }

        bool is_palindrome = true;
        determine(head, 0, length, is_palindrome);

        return is_palindrome;
    }
};

} // namespace wb

#endif
