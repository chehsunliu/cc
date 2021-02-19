#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

//#include "snippet/snippet.hpp"

using i64 = int64_t;

i64 getValidCount(i64 array[], const int &n) {
    std::sort(array, array + n);

    if (n % 2 == 1) {
        return 1;
    }

    return array[n / 2] - array[n / 2 - 1] + 1;
}

// 10^10 = (10^3)^3*10 = 2^30 * 10
// 10^18 = (10^3)^6 = 2^60
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    i64 xs[1001];
    i64 ys[1001];

    for (; t > 0; t--) {
        int n;
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            std::cin >> xs[i] >> ys[i];
        }

        i64 validXCount = getValidCount(xs, n);
        i64 validYCount = getValidCount(ys, n);
        std::cout << validXCount * validYCount << "\n";
    }

    return 0;
}