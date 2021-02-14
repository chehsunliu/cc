#ifndef __APPLESS_H__
#define __APPLESS_H__

#include <algorithm>
#include <map>
#include <string>

#include "appless/leetcode.hpp"

using namespace std;

namespace appless {

class Solution {
  public:
    Solution() {
        lookup.emplace('2', "abc");
        lookup.emplace('3', "def");
        lookup.emplace('4', "ghi");
        lookup.emplace('5', "jkl");
        lookup.emplace('6', "mno");
        lookup.emplace('7', "pqrs");
        lookup.emplace('8', "tuv");
        lookup.emplace('9', "wxyz");
    }

    void combine(const string &digits, int index, string answer, vector<string> &answers) {
        if (index >= digits.size()) {
            answers.push_back(answer);
            return;
        }

        string letters = lookup[digits[index]];
        for (char c : letters) {
            combine(digits, index + 1, answer + c, answers);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> answers;
        if (digits.empty()) {
            return answers;
        }

        combine(digits, 0, "", answers);
        return answers;
    }

  private:
    map<char, string> lookup;
};

} // namespace appless

#endif
