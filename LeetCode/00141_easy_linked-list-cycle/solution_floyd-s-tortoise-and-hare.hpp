#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <climits>
#include <algorithm>
#include <vector>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }

        ListNode *tortoise = head;
        ListNode *hare = head;

        while (hare->next != NULL && hare->next->next != NULL) {
            tortoise = tortoise->next;
            hare = hare->next->next;

            if (tortoise == hare) {
                return true;
            }
        }

        return false;
    }
};

}

#endif
