#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <vector>
#include <algorithm>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            if (i == 0) {
                ans.push_back(vector<int>(1, 1));
                continue;
            }

            vector<int> tmp(i + 1);
            for (int j = 0; j < i + 1; j++) {
                int n0 = j - 1 < 0 ? 0 : ans[i - 1][j - 1];
                int n1 = j >= i ? 0 : ans[i - 1][j];
                tmp[j] = n0 + n1;
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};

}

#endif
