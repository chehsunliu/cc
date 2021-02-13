#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <algorithm>
#include <unordered_map>
#include <vector>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans(2);
        int l = 0;
        int r = numbers.size() - 1;

        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                ans[0] = l + 1;
                ans[1] = r + 1;
                break;
            }

            if (sum > target) {
                r--;
            } else {
                l++;
            }
        }

        return ans;
    }
};

} // namespace wb

#endif
