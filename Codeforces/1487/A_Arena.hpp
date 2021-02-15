#include <algorithm>
#include <iostream>
#include <vector>

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
        std::vector<int> counts(101, 0);

        int n;
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            int level;
            std::cin >> level;
            counts[level]++;
        }

        int lowestLevelCount = 0;
        for (int count : counts) {
            if (count != 0) {
                lowestLevelCount = count;
                break;
            }
        }

        std::cout << n - lowestLevelCount << "\n";
    }

    return 0;
}