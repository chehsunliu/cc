#ifndef __WBLIB_H__
#define __WBLIB_H__

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return true;
        } else if (root->left == nullptr || root->right == nullptr) {
            return false;
        }

        return this->_isSymmetric(root->left, root->right);
    }

private:
    bool _isSymmetric(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        }

        return p->val == q->val && _isSymmetric(p->left, q->right) && _isSymmetric(p->right, q->left);
    }
};

}


#endif
