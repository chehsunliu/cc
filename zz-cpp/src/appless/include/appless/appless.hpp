#ifndef __APPLESS_H__
#define __APPLESS_H__

#include <cstdio>

#include <algorithm>
#include <string>
#include <unordered_map>

#include "appless/leetcode.hpp"

using namespace std;

namespace appless {

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left <= right) {
            int area = (right - left) * min(height[left], height[right]);
            max_area = max(max_area, area);
            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }

        return max_area;
    }
};

} // namespace appless

#endif
