#include <algorithm>
#include <iostream>
#include <vector>

//#include "codebook/codebook.hpp"

typedef long long cc_int;

#ifdef __SIZEOF_INT128__
typedef __int128 int128;
#endif

// 10^10 = (10^3)^3*10 = 2^30 * 10
// 10^18 = (10^3)^6 = 2^60
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    for (; t > 0; t--) {
        int n, k;
        std::cin >> n >> k;

        k--;
        int ans;

        if (n % 2 == 0) {
            ans = k % n;
        } else {
            if (k < n / 2) {
                ans = k;
            } else {
                k -= n / 2;
                int div = k / (n / 2);
                int pos = n / 2 + 1;
                pos += div * (n / 2 + 1) + k % (n / 2);
                pos %= n;
                ans = pos;
            };
        }

        std::cout << ans + 1 << "\n";

        // n = 3
        // 3 2 1 3 2 1
        // 1 3 2
        //   ^ ^
        // n = 5
        // 5 4 3 2 1 5 4 3 2 1 5 4 3 2 1
        // 4 3 2 1 0 4 3 2 1 0 4 3 2 1 0
        // 0 1 3 4 1 2 4 0 2 3 0 1 3 4 1
        //     ^   ^   ^   ^   ^   ^   ^
        // n = 7
        // 7 6 5 4 3 2 1 7 6 5 4 3 2 1 7 6 5 4 3 2 1
        // 1 2 3 5 6 7 2 3 4 6 7 1 3 4 5 7 1 2 4 5 6
        //       ^     ^     ^     ^     ^     ^
        // n = 9
        // 9 8 7 6 5 4 3 2 1 9 8 7 6 5 4 3 2 1 9 8 7 6 5 4 3 2 1
        // 1 2 3 4 6 7 8 9 2 3 4 5 7 8 9 1 3 4 5 6 8 9 1 2 4 5 6
        //         ^       ^       ^       ^       ^       ^
    }

    return 0;
}