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
    bool _isBalanced(TreeNode *root, int &layer) {
        if (root == nullptr) {
            layer = 0;
            return true;
        }

        int layer_l = 0;
        int layer_r = 0;

        if (!_isBalanced(root->left, layer_l) || !_isBalanced(root->right, layer_r)) {
            return false;
        }

        layer = 1 + max(layer_r, layer_l);
        return (layer_l - layer_r) * (layer_l - layer_r) <= 1;
    }

    bool isBalanced(TreeNode *root) {
        int layer = 0;
        return _isBalanced(root, layer);
    }
};

}


#endif
