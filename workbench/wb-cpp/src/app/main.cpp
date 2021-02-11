#include <algorithm>
#include <cmath>
#include <iostream>

//#include <snippet/snippet.hpp>

typedef long long cc_int;
typedef __int128 int128;

// O(n^3)
cc_int solve1(const cc_int &N) {
    cc_int count = 0;

    cc_int sum = (N + 1) * N / 2;

    for (cc_int i = 1; i <= N; i++) {
        for (cc_int j = i + 1; j <= N; j++) {
            for (cc_int m = 1; m < N; m++) {
                cc_int sumLeft = m * (m + 1) / 2;
                cc_int sumRight = sum - sumLeft;

                if (j <= m || i > m) {
                    count += sumLeft == sumRight;
                } else {
                    sumLeft = sumLeft - i + j;
                    sumRight = sumRight - j + i;
                    count += sumLeft == sumRight;
                }
            }
        }
    }
    return count;
}

// O(N)
cc_int solve2(const cc_int &N) {
    cc_int count = 0;

    for (cc_int m = 1; m < N; m++) {
        cc_int diff2 = N * (N + 1) / 2 - m * (m + 1);
        if (diff2 < 0 || diff2 % 2 != 0) {
            continue;
        }

        cc_int diff = diff2 / 2;
        if (diff >= N) {
            continue;
        }

        if (diff == 0) {
            count += m * (m - 1) / 2;
            count += N - m > 0 ? (N - m) * (N - m - 1) / 2 : 0;
        } else {
            count += std::min(N - diff, m) - std::max(m + 1 - diff, 1LL) + 1;
        }
    }

    return count;
}

// O(1)
cc_int solve3(const cc_int &N) {
    cc_int count = 0;

    cc_int mStart = (std::sqrt((N * N - 3 * N + 4) * 2 + 1) - 1) / 2;
    mStart = std::max(mStart, 1LL);

    cc_int mEnd = (std::sqrt((N * N + 5 * N - 4) * 2 + 1) - 1) / 2;
    mEnd = std::min(mEnd, N - 1);

    for (cc_int m = mStart; m <= mEnd; m++) {
        cc_int diff2 = N * (N + 1) / 2 - m * (m + 1);
        if (diff2 < 0 || diff2 % 2 != 0) {
            continue;
        }

        cc_int diff = diff2 / 2;
        if (diff >= N) {
            continue;
        }

        if (diff == 0) {
            count += m * (m - 1) / 2;
            count += N - m > 0 ? (N - m) * (N - m - 1) / 2 : 0;
        } else {
            count += std::min(N - diff, m) - std::max(m + 1 - diff, 1LL) + 1;
        }
    }

    return count;
}

// 10^10 = (10^3)^3*10 = 2^30 * 10
// 10^18 = (10^3)^6 = 2^60
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T, N;
    std::cin >> T;

    for (int t = 0; t < T; t++) {
        std::cin >> N;
        std::cout << solve3(N) << "\n";
    }

    return 0;
}