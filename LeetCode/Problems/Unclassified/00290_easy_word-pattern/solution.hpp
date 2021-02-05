#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <cstdio>

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    bool wordPattern(string pattern, string s) {
        vector<string> words = cut(s);
        if (pattern.length() != words.size()) {
            return false;
        }

        unordered_map<string, char> map;
        unordered_set<char> used_chars;

        for (size_t i = 0; i < words.size(); i++) {
            auto mapped_char = map.find(words[i]);

            if (mapped_char != map.end()) {
                if (mapped_char->second != pattern[i]) {
                    return false;
                }
            } else {
                if (used_chars.find(pattern[i]) != used_chars.end()) {
                    return false;
                }
                map.insert(make_pair(words[i], pattern[i]));
                used_chars.insert(pattern[i]);
            }
        }

        return true;
    }

  private:
    vector<string> cut(string s) {
        vector<string> result;

        size_t pos = 0;
        string delimiter = " ";
        string token;

        while ((pos = s.find(delimiter)) != string::npos) {
            token = s.substr(0, pos);
            result.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        if (!s.empty()) {
            result.push_back(s);
        }

        return result;
    }
};

} // namespace wb

#endif
