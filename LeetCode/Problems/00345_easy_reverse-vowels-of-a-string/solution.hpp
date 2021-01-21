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
    string reverseVowels(string s) {
        vector<int> vowel_indexes;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
                || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                vowel_indexes.push_back(i);
            }
        }

        for (int i = 0; i < vowel_indexes.size() / 2; i++) {
            swap(s[vowel_indexes[i]], s[vowel_indexes[vowel_indexes.size() - i - 1]]);
        }

        return s;
    }
};

} // namespace wb

#endif
