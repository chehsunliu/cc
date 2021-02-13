#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <cmath>

#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        unordered_set<char> mapped_values;

        for (int i = 0; i < s.length(); i++) {
            char char_s = s[i];
            char char_t = t[i];

            unordered_map<char, char>::const_iterator map_got = map.find(char_s);
            if (map_got != map.end()) {
                if (map_got->second != char_t) {
                    return false;
                }
            } else {
                if (mapped_values.find(char_t) != mapped_values.end()) {
                    return false;
                }
                map.insert(char_s, char_t);
                mapped_values.insert(char_t);
            }
        }

        return false;
    }
};

} // namespace wb

#endif
