#ifndef __APPLESS_H__
#define __APPLESS_H__

#include "appless/leetcode.hpp"

using namespace std;
using namespace leetcode;

namespace appless {

class Solution {
public:
    ListNode *traverse(ListNode *node, int index) {
        if (node == nullptr) {
            return nullptr;
        }

        ListNode *nextNode = traverse(node->next, index + 1);
        if (index % 2 == 1) {
            node->next = nextNode;
            return node;
        } else {
            nextNode = node->next;
            if (nextNode != nullptr) {
                node->next = nextNode->next;
                nextNode->next = node;
                return nextNode;
            } else {
                return node;
            }
        }
    }

    ListNode *swapPairs(ListNode *head) { return traverse(head, 0); }
};

}  // namespace appless

#endif
