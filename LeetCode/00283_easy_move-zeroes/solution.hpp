#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <algorithm>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        int base = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[base]);
                base++;
            }
        }
    }
};

} // namespace wb

#endif
