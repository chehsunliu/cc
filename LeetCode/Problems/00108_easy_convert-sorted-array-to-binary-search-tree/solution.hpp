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
    TreeNode *convert(vector<int> &nums, const int left, const int right) {
        if (left > right) {
            return nullptr;
        }

        int middle = (left + right) / 2;

        return new TreeNode(
                nums[middle],
                convert(nums, left, middle - 1),
                convert(nums, middle + 1, right)
        );
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return convert(nums, 0, nums.size() - 1);
    }
};

}


#endif
