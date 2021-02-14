#ifndef __APPLESS_LEETCODE_H__
#define __APPLESS_LEETCODE_H__

#include <algorithm>
#include <climits>
#include <map>
#include <set>
#include <vector>

namespace leetcode {

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    // Customization
    static ListNode *from_vector(const std::vector<int> &nums) {
        if (nums.empty()) {
            return nullptr;
        }

        auto *ptr = new ListNode(nums[0]);
        ListNode *head = ptr;
        for (int i = 1; i < nums.size(); i++) {
            ptr->next = new ListNode(nums[i]);
            ptr = ptr->next;
        }
        return head;
    }
    ~ListNode() { delete next; }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

} // namespace leetcode

#endif
