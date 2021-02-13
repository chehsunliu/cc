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
        unordered_map<int, int> map;
        vector<int> ans;

        for (int i = 0; i < numbers.size(); i++) {
            int complement = target - numbers[i];
            unordered_map<int, int>::const_iterator got = map.find(complement);
            if (got != map.end()) {
                ans[0] = got->second + 1;
                ans[1] = i + 1;
                break;
            } else {
                map.insert(make_pair(numbers[i], i));
            }
        }

        return ans;
    }
};

} // namespace wb

#endif
