#include <algorithm>
#include <iostream>
#include <vector>

//#include "snippet/snippet.hpp"

typedef unsigned long long m_int;
typedef __int128 int128;

// O(n * 2^n)
int solution1(const std::vector<m_int> &numbers, const m_int &K) {
    int count = 0;

    int choices = (1 << numbers.size()) - 1;
    for (int i = 1; i <= choices; i++) {
        int128 product = 1;
        int choice = i;
        for (auto &number : numbers) {
            product *= choice % 2 == 1 ? number : 1;
            choice /= 2;

            if (product > K) {
                break;
            }
        }

        if (product <= K) {
            count++;
        }
    }

    return count;
}

std::vector<int128> findPossibles(const std::vector<m_int> &numbers, const m_int &K, size_t begin, size_t end) {
    std::vector<int128> result;

    int choices = (1 << (end - begin)) - 1;
    for (int i = 1; i <= choices; i++) {
        int128 product = 1;
        int choice = i;
        for (int j = begin; j < end; j++) {
            product *= choice % 2 == 1 ? numbers[j] : 1;
            choice /= 2;

            if (product > K) {
                break;
            }
        }

        if (product <= K) {
            result.push_back(product);
        }
    }

    return result;
}

// O(2 * (n/2) * 2^(n/2))
// = O(n * 2^(n/2))
int solution2(const std::vector<m_int> &numbers, const m_int &K) {
    int count = 0;

    size_t left_size = numbers.size() / 2;
    std::vector<int128> L = findPossibles(numbers, K, 0, left_size);
    std::vector<int128> R = findPossibles(numbers, K, left_size, numbers.size());
    L.push_back(1);
    R.push_back(1);

    std::sort(L.begin(), L.end());
    std::sort(R.begin(), R.end());
    for (auto &l : L) {
        auto loc = std::upper_bound(R.begin(), R.end(), K / l);
        count += loc - R.begin();
    }

    return count - 1;
}

// https://www.codechef.com/MAY17/problems/CHEFCODE
// 10^10 = (10^3)^3*10 = 2^30 * 10
// 10^18 = (10^3)^6 = 2^60
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    m_int K;
    std::cin >> N >> K;

    std::vector<m_int> numbers(N, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> numbers[i];
    }

    std::cout << solution2(numbers, K) << std::endl;

    return 0;
}