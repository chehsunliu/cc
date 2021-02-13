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
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    void traverse(TreeNode *node, vector<vector<int>> &ans, int layer) {
        if (node == nullptr) {
            return;
        }

        ans[layer].push_back(node->val);
        traverse(node->left, ans, layer - 1);
        traverse(node->right, ans, layer - 1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        int depth = maxDepth(root);

        vector<vector<int>> ans;
        for (int i = 0; i < depth; i++) {
            ans.push_back(vector<int>());
        }

        traverse(root, ans, depth - 1);

        return ans;
    }
};

}


#endif
