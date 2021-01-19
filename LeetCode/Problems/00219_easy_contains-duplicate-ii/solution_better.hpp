#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <cmath>

#include <algorithm>
#include <unordered_set>
#include <vector>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_set<int> set;

        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                set.erase(nums[i - k - 1]);
            }

            if (set.find(nums[i]) != set.end()) {
                return true;
            }

            set.insert(nums[i]);
        }

        return false;
    }
};

} // namespace wb

#endif
