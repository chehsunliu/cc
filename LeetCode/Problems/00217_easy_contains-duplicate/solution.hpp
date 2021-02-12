#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <cmath>

#include <algorithm>
#include <vector>
#include <unordered_set>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> storage;

        for (auto num : nums) {
            storage.insert(num);
        }

        return nums.size() != storage.size();
    }
};

} // namespace wb

#endif
