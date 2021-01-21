#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <cstdio>

#include <vector>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }

        while (n != 1) {
            if (n % 3 != 0) {
                return false;
            } else {
                n /= 3;
            }
        }

        return true;
    }
};

} // namespace wb

#endif
