#include <iostream>
#include <vector>

//#include "snippet/snippet.hpp"

typedef unsigned long long m_int;
typedef __int128 int128;

int solveByBruteForce(const std::vector<m_int> &numbers, int index, int128 product, const int128 &K) {
    if (index >= numbers.size()) {
        return product <= K ? 1 : 0;
    } else if (product > K) {
        return 0;
    }

    return solveByBruteForce(numbers, index + 1, product * numbers[index], K) +
           solveByBruteForce(numbers, index + 1, product, K);
}

// 10^10 = (10^3)^3*10 = 2^30 * 10
// 10^18 = (10^3)^6 = 2^60
int main() {
    std::ios_base::sync_with_stdio(false);

    int N, K;
    std::cin >> N >> K;

    std::vector<m_int> numbers(N, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> numbers[i];
    }

    std::cout << solveByBruteForce(numbers, 0, 1, K) - 1 << std::endl;

    return 0;
}