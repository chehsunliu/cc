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
        int min_price = INT_MAX;
        int max_profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            } else {
                int profit = prices[i] - min_price;
                max_profit = max(max_profit, profit);
            }
        }

        return max_profit;
    }
};

}

#endif
