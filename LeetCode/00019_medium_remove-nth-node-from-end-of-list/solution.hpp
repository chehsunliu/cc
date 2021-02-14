#ifndef __APPLESS_H__
#define __APPLESS_H__

#include <algorithm>
#include <climits>
#include <map>
#include <tuple>

#include "appless/leetcode.hpp"

using namespace std;
using namespace leetcode;

namespace appless {

class Solution {
  public:
    ListNode *concat(ListNode *node, int &n) {
        if (node == nullptr) {
            return node;
        }

        ListNode *next = concat(node->next, n);
        n--;

        if (n == 0) {
            return next;
        } else {
            node->next = next;
            return node;
        }
    }

    ListNode *removeNthFromEnd(ListNode *head, int n) { return concat(head, n); }
};

} // namespace appless

#endif
