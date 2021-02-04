#include <cstdio>
#include <vector>

//#include "snippet/snippet.hpp"

bool solve(const std::vector<int> &nums, const int &K) {
    std::vector<bool> dp(K + 1, false);
    dp[0] = true;

    for (int i = 1; i <= nums.size(); i++) {
        std::vector<bool> tmp(K + 1, false);
        tmp[0] = true;

        for (int k = 1; k <= K; k++) {
            bool left = dp[k];
            bool right = k - nums[i - 1] >= 0 && dp[k - nums[i - 1]];

            tmp[k] = left || right;
        }

        dp = tmp;
    }

    return dp[K];
}

int main() {
    int T;
    int N, K;

    std::scanf("%d", &T);

    while (std::scanf("%d %d", &N, &K) != EOF) {
        std::vector<int> nums(N, 0);
        for (int i = 0; i < N; i++) {
            scanf("%d", &nums[i]);
        }

        printf("%d\n", int(solve(nums,  K)));
    }

    return 0;
}