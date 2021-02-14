#ifndef __APPLESS_H__
#define __APPLESS_H__

#include <algorithm>
#include <climits>
#include <map>
#include <tuple>

#include "appless/leetcode.hpp"

using namespace std;

namespace appless {

class Solution {
  public:
    // O(n^3)
    int solve1(vector<int> &nums, int target) {
        int minDiff = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    int diff = nums[i] + nums[j] + nums[k] - target;
                    minDiff = std::abs(diff) < std::abs(minDiff) ? diff : minDiff;
                }
            }
        }

        return target + minDiff;
    }

    // O(n^2)
    int solve2(vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int current = nums[i] + nums[l] + nums[r];
                if (current == target) {
                    return target;
                } else if (current > target) {
                    r--;
                } else {
                    l++;
                }
                minDiff = abs(current - target) < abs(minDiff) ? current - target : minDiff;
            }
        }

        return target + minDiff;
    }

    int threeSumClosest(vector<int> &nums, int target) { return solve2(nums, target); }
};

} // namespace appless

#endif
