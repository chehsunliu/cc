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
        if (head == nullptr) {
            return head;
        }

        stack<ListNode*> storage;

        ListNode *ptr = head;
        while (ptr->next != nullptr) {
            storage.push(ptr);
            ptr = ptr->next;
        }

        head = ptr;
        while (!storage.empty()) {
            ptr->next = storage.top();
            storage.pop();
            ptr = ptr->next;
        }
        ptr->next = nullptr;

        return head;
    }
};

} // namespace wb

#endif
