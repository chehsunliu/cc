#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <stack>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

} // namespace wb

#endif
