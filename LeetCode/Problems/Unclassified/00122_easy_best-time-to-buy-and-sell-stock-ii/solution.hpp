#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <climits>
#include <algorithm>
#include <vector>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            profit += prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0;
        }

        return profit;
    }
};

}

#endif
