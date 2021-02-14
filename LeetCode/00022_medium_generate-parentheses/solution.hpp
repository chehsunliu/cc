#ifndef __APPLESS_H__
#define __APPLESS_H__

#include "appless/leetcode.hpp"

using namespace std;

namespace appless {

// n = 1
// ()
//
// n = 2
// (()), ()()
class Solution {
  public:
    void track(int n, string answer, vector<string> &answers, int left, int right) {
        if (answer.size() == 2 * n) {
            answers.push_back(answer);
            return;
        }

        if (left < n) {
            track(n, answer + "(", answers, left + 1, right);
        }
        if (right < left) {
            track(n, answer + ")", answers, left, right + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> answers;
        track(n, "", answers, 0, 0);
        return answers;
    }
};

} // namespace appless

#endif
