#ifndef __APPLESS_H__
#define __APPLESS_H__

#include <algorithm>
#include <climits>
#include <map>
#include <set>

#include "appless/leetcode.hpp"

using namespace std;

namespace appless {

class Solution {
  public:
    // O(n^4)
    vector<vector<int>> solve1(vector<int> &nums, int target) {
        vector<vector<int>> answers;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    for (int l = k + 1; l < nums.size(); l++) {
                        if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                            vector<int> answer({nums[i], nums[j], nums[k], nums[l]});
                            answers.push_back(answer);
                        }
                    }
                }
            }
        }

        return answers;
    }

    // O(n^3)
    vector<vector<int>> solve2(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> answers;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    int current = nums[i] + nums[j] + nums[left] + nums[right];
                    if (current == target) {
                        vector<int> answer({nums[i], nums[j], nums[left], nums[right]});
                        answers.insert(answer);
                        right--;
                        left++;
                    } else if (current > target) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }

        return vector<vector<int>>(answers.begin(), answers.end());
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target) { return solve2(nums, target); }
};

} // namespace appless

#endif
