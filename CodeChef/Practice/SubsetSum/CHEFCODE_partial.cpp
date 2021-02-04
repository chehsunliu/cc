#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

//#include "snippet/snippet.hpp"

typedef unsigned long long m_int;

int solveByBruteForce(const std::vector<m_int> &numbers, int index, double logProduct, const double &logK) {
    if (index >= numbers.size()) {
        return logProduct <= logK ? 1 : 0;
    }

    return solveByBruteForce(numbers, index + 1, logProduct + std::log(numbers[index]), logK) +
           solveByBruteForce(numbers, index + 1, logProduct, logK);
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

    std::cout << solveByBruteForce(numbers, 0, 0, std::log(K)) - 1 << std::endl;

    return 0;
}