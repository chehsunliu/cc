#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <cstdio>

#include <algorithm>
#include <string>
#include <vector>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  private:
    int traverse(TreeNode *node, const bool is_from_left) {
        if (node->left == nullptr && node->right == nullptr) {
            return is_from_left ? node->val : 0;
        } else {
            int sum = 0;
            if (node->left != nullptr) {
                sum += traverse(node->left, true);
            }
            if (node->right != nullptr) {
                sum += traverse(node->right, false);
            }
            return sum;
        }
    }

  public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        return traverse(root, false);
    }
};

} // namespace wb

#endif
