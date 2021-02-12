#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <cstdio>

#include <vector>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class NumArray {
  public:
    NumArray(vector<int> &nums) {
        this->sums.reserve(nums.size());

        int sum = 0;
        for (int num : nums) {
            sum += num;
            this->sums.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        int ans = this->sums.back();
        ans -= i > 0 ? this->sums[i - 1] : 0;
        ans -= j < this->sums.size() - 1 ? this->sums.back() - this->sums[j] : 0;
        return ans;
    }

  private:
    vector<int> sums;
};

} // namespace wb

#endif
