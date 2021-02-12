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
    int longestPalindrome(string s) {
        unordered_map<char, int> map;

        for (auto &c: s) {
            auto got = map.find(c);
            if (got == map.end()) {
                map.insert(make_pair(c, 1));
            } else {
                got->second++;
            }
        }

        bool has_orphan = false;
        int length = 0;
        for (auto &iter: map) {
            if (iter.second % 2 == 1) {
                has_orphan = true;
            }
            if (iter.second >= 2) {
                length += iter.second - (iter.second % 2);
            }
        }

        return length + has_orphan;
    }
};

} // namespace wb

#endif
