#include <cstdio>

//#include "snippet/snippet.hpp"

typedef long long m_int;
#define MODULUS 1000000009
#define BUFFER_SIZE 1000001

m_int solve(m_int scores, m_int dp[BUFFER_SIZE]) {
    if (scores == 0) {
        return 1;
    } else if (scores < 0) {
        return 0;
    }

    if (dp[scores] >= 0) {
        return dp[scores];
    }

    dp[scores] = (solve(scores - 2, dp) + solve(scores - 3, dp)) % MODULUS;
    return dp[scores];
}

int main() {
    int T;
    scanf("%d", &T);

    m_int dp[BUFFER_SIZE];
    for (int i = 0; i < BUFFER_SIZE; i++) {
        dp[i] = -1;
    }

    for (int t = 0; t < T; t++) {
        m_int N;
        scanf("%lld", &N);
        printf("%lld\n", solve(N, dp));
    }

    return 0;
}