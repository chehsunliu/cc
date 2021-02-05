#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <cstdio>

#include <algorithm>
#include <string>
#include <vector>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    bool isPerfectSquare(int num) {
        long long left = 1;
        long long right = num ;

        while (left <= right) {
            long long middle = (left + right) / 2;
            long long middle_squared = middle * middle;

            if (middle_squared == num) {
                return true;
            } else if (middle_squared < num) {
                left = middle + 1;
            } else {
                right = middle -1;
            }
        }

        return false;
    }
};

} // namespace wb

#endif
