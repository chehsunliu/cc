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
        while (n > 1) {
            int nn = n;
            n = 0;
            while (nn > 0) {
                int digit = nn % 10;
                nn /= 10;
                n += digit * digit;
            }
            if (n == 4) {
                return false;
            }
        }
        return true;
    }
};

} // namespace wb

#endif
