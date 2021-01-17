#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <vector>
#include <algorithm>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int depth_l = minDepth(root->left);
        int depth_r = minDepth(root->right);

        if (depth_l == 0 || depth_r == 0) {
            return 1 + max(depth_l, depth_r);
        } else {
            return 1 + min(depth_l, depth_r);
        }
    }
};

}

#endif
