#ifndef __WBLIB_H__
#define __WBLIB_H__

#include <queue>
#include <tuple>

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
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return true;
        }

        std::queue<std::tuple<TreeNode *, TreeNode *>> q;
        q.push(std::make_tuple(root->left, root->right));

        while (!q.empty()) {
            std::tuple<TreeNode *, TreeNode *> pair = q.front();
            TreeNode *n0 = std::get<0>(pair);
            TreeNode *n1 = std::get<1>(pair);
            q.pop();

            if (n0 == nullptr && n1 == nullptr) {
                continue;
            }

            if (n0 == nullptr || n1 == nullptr || n0->val != n1->val) {
                return false;
            }

            q.push(std::make_tuple(n0->left, n1->right));
            q.push(std::make_tuple(n0->right, n1->left));
        }

        return true;
    }
};

}


#endif
