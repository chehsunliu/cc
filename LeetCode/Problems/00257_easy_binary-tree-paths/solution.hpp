#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <string>
#include <vector>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> answers;
        this->traverse(root, "", answers);
        return answers;
    }

  private:
    void traverse(TreeNode *node, const string& answer, vector<string> &answers) {
        if (node == nullptr) {
            return;
        }

        string current_value = to_string(node->val);
        string modified_answer = answer.empty() ? current_value : answer + "->" + current_value;

        if (node->left == nullptr && node->right == nullptr) {
            answers.push_back(modified_answer);
        } else {
            traverse(node->left, modified_answer, answers);
            traverse(node->right, modified_answer, answers);
        }
    }
};

} // namespace wb

#endif
