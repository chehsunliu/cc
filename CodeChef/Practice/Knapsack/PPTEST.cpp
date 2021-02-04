#include <algorithm>
#include <cstdio>
#include <vector>

//#include "snippet/snippet.hpp"

class Question {
  public:
    int tests;
    int points_per_tests;
    int time;

    Question() {
        this->tests = 0;
        this->points_per_tests = 0;
        this->time = 0;
    }
};

#define BUFFER_SIZE 101

int solve_dp(Question questions[BUFFER_SIZE], int size, int W) {
    std::vector<int> dp(W + 1, 0);

    for (int i = 1; i <= size; i++) {
        std::vector<int> tmp(W + 1, 0);

        for (int w = 1; w <= W; w++) {
            int left = dp[w];
            int right = w - questions[i - 1].time >= 0
                            ? dp[w - questions[i - 1].time] + questions[i - 1].tests * questions[i - 1].points_per_tests
                            : 0;
            tmp[w] = std::max(left, right);
        }

        dp = tmp;
    }

    return dp[W];
}

int main() {
    int T;
    int N, W;
    Question questions[BUFFER_SIZE];

    std::scanf("%d", &T);

    while (std::scanf("%d %d", &N, &W) != EOF) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &questions[i].tests);
            scanf("%d", &questions[i].points_per_tests);
            scanf("%d", &questions[i].time);
        }

        printf("%d\n", solve_dp(questions, N, W));
    }

    return 0;
}