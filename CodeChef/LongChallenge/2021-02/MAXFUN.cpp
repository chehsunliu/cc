#include <algorithm>
#include <iostream>
#include <vector>

//#include "snippet/snippet.hpp"

typedef long long cc_int;

#ifdef __SIZEOF_INT128__
typedef __int128 int128;
#endif

cc_int solution(std::vector<cc_int> &numbers) {
    std::sort(numbers.begin(), numbers.end());
    return (numbers[numbers.size() - 1] - numbers[0]) * 2;
}

// 10^10 = (10^3)^3*10 = 2^30 * 10
// 10^18 = (10^3)^6 = 2^60
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        std::cin >> N;

        std::vector<cc_int> numbers(N, 0);
        for (int i = 0; i < N; i++) {
            std::cin >> numbers[i];
        }

        std::cout << solution(numbers) << std::endl;
    }

    return 0;
}