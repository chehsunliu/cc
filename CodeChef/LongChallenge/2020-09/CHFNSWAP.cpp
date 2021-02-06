#include <cassert>
#include <cmath>
#include <cstdio>
#include <algorithm>

typedef long long  my_int;

#ifndef RUN_IN_GTEST

// 2^32 == (2^10)^3 * 4 ~= 10^9 * 4
// 2^64 == (2^10)^6 * 16 ~= 10^18 * 16
int main(int argc, char *args[]) {
    int T;
    scanf("%d", &T);

    my_int N;
    while (scanf("%lld", &N) != EOF) {
        my_int count = 0;
        my_int K = 2 * N * (N + 1) + 1;

        for (my_int i = sqrt(K + 1); i > 0; i--) {
            if (i % 2 == 0) {
                continue;
            }

            my_int m = (i - 1) / 2;
            if (m >= N || m < 1) {
                continue;
            }

            my_int target_square = i * i;

            my_int remaining = K - target_square;
            if (remaining % 8) {
                continue;
            }

            my_int d = remaining / 8;
            if (d >= N) {
                break;
            }

            if (d == 0) {
                count += m * (m - 1) / 2;
                count += (N - m) * (N - m - 1) / 2;
            } else {
                count += std::min(N - d, m) - std::max(m + 1 - d, 1LL) + 1;
            }
        }

        printf("%lld\n", count);
    }

    return 0;
}

#endif