#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <cmath>

#include <algorithm>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }

        TreeNode *tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};

} // namespace wb

#endif
