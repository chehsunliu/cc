#ifndef __WBLIB_H__
#define __WBLIB_H__

#include <vector>
#include <algorithm>

using namespace std;

namespace wb {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
