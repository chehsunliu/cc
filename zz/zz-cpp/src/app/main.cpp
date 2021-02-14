#include <algorithm>
#include <iostream>

//#include "snippet/snippet.hpp"

typedef long long cc_int;

#ifdef __SIZEOF_INT128__
typedef __int128 int128;
#endif

int solve(int a, int b) {
    if (a < b) {
        return 1;
    } else if (a == b) {
        return 2;
    }

    int ans = 10000;

    for (int i = 0; i < 50; i++) {
        int currentB = b + i;
        if (currentB == 1) {
            continue;
        }

        int count = i;
        int tmpA = a;
        while (tmpA != 0) {
            tmpA /= currentB;
            count++;
        }

        ans = std::min(ans, count);
    }

    return ans;
}

// 10^10 = (10^3)^3*10 = 2^30 * 10
// 10^18 = (10^3)^6 = 2^60
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++) {
        int a, b;
        std::cin >> a >> b;
        std::cout << solve(a, b) << "\n";
    }

    return 0;
}