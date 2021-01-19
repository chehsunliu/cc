#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <algorithm>
#include <unordered_set>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    bool isHappy(int n) {
        int ans_1x = calculate_1x(n);
        int ans_2x = calculate_2x(n);

        while (ans_1x != ans_2x) {
            ans_1x = calculate_1x(ans_1x);
            ans_2x = calculate_2x(ans_2x);
        }

        return ans_1x == 1;
    }

  private:
    int calculate_1x(const int &n) {
        int ans = 0;
        int nn = n;
        while (nn > 0) {
            int digit = nn % 10;
            nn /= 10;
            ans += digit * digit;
        }
        return ans;
    }
    int calculate_2x(const int &n) { return calculate_1x(calculate_1x(n)); }
};

} // namespace wb

#endif
