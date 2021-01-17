#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <vector>
#include <algorithm>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return false;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return sum == root->val;
        }

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

}

#endif
