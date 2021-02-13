#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <algorithm>
#include <string>
#include <vector>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> ans;
        if (nums.empty()) {
            return ans;
        }

        int base = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1] + 1) {
                if (nums[i - 1] == base) {
                    ans.push_back(to_string(base));
                } else {
                    ans.push_back(to_string(base) + "->" + to_string(nums[i - 1]));
                }
                base = nums[i];
            }
        }

        if (nums[nums.size() - 1] == base) {
            ans.push_back(to_string(base));
        } else {
            ans.push_back(to_string(base) + "->" + to_string(nums[nums.size() - 1]));
        }

        return ans;
    }
};

} // namespace wb

#endif
