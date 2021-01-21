#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <cstdio>

#include <vector>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    bool isPowerOfFour(int n) {
        if (n < 1) {
            return false;
        }

        while (n != 1) {
            if (n % 4 != 0) {
                return false;
            } else {
                n /= 4;
            }
        }

        return true;
    }
};

} // namespace wb

#endif
