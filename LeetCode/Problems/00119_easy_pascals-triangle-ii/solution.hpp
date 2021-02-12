#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <vector>
#include <algorithm>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev_row(1, 1);

        for (int i = 1; i <= rowIndex; i++) {
            vector<int> tmp(i + 1);
            for (int j = 0; j < i + 1; j++) {
                int n0 = j - 1 < 0 ? 0 : prev_row[j - 1];
                int n1 = j >= i ? 0 : prev_row[j];
                tmp[j] = n0 + n1;
            }
            prev_row = tmp;
        }

        return prev_row;
    }
};

}

#endif
