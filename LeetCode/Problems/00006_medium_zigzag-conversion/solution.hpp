#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <cstdio>

#include <algorithm>
#include <string>
#include <unordered_map>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    string convert(string s, int numRows) {
        int base = numRows * 2 - 2;
        if (base == 0) {
            return s;
        }
        string ans;

        int offset = base - 2;
        for (int row = 0; row < numRows; row++) {
            if (row == 0 || row == numRows - 1) {
                for (int i = row; i < s.length(); i+= base) {
                    ans += s[i];
                }
            } else {
                for (int i = row; i < s.length(); i += base) {
                    ans += s[i];
                    if (i + offset < s.length()) {
                        ans += s[i + offset];
                    }
                }
                offset -= 2;
            }
        }

        return ans;
    }
};

} // namespace wb

#endif
