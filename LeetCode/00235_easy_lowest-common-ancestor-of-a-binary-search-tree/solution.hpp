#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (p->val == root->val || q->val == root->val) {
            return root;
        }

        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else if ((p->val > root->val && root->val > q->val) || q->val > root->val && root->val > p->val) {
            return root;
        } else {
            return lowestCommonAncestor(root->left, p, q);
        }
    }
};

} // namespace wb

#endif
