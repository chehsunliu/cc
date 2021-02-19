#include <algorithm>
#include <iostream>
#include <climits>

//#include "snippet/snippet.hpp"

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
        int n;
        std::cin >> n;

        int64_t minimalBoxes = 0;
        int64_t accumulatedBoxes = 0;
        bool isValid = true;

        for (int i = 0; i < n; i++) {
            int64_t height;
            std::cin >> height;

            minimalBoxes += i;
            accumulatedBoxes += height;
            isValid &= accumulatedBoxes >= minimalBoxes;
        }

        if (isValid) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}