#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <stack>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    int addDigits(int num) {
        while (num / 10 != 0) {
            int tmp = 0;
            while (num != 0) {
                tmp += num % 10;
                num /= 10;
            }
            num = tmp;
        }
        return num;
    }
};

} // namespace wb

#endif
