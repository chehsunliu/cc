#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <cmath>

#include <algorithm>
#include <unordered_map>
#include <vector>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, vector<int>> map;

        for (int i = 0; i < nums.size(); i++) {
            auto got = map.find(nums[i]);
            if (got == map.end()) {
                vector<int> indexes;
                indexes.push_back(i);
                map.insert(make_pair(nums[i], indexes));
            } else {
                got->second.push_back(i);
            }
        }

        for (auto &it : map) {
            if (it.second.size() <= 1) {
                continue;
            }

            sort(it.second.begin(), it.second.end());
            for (int i = 1; i < it.second.size(); i++) {
                if (it.second[i] - it.second[i - 1] <= k) {
                    return true;
                }
            }
        }

        return false;
    }
};

} // namespace wb

#endif
