#include <iostream>
#include <unordered_map>
#include <vector>

//#include "snippet/snippet.hpp"

typedef unsigned long long m_int;
typedef __int128 int128;

// O(n^4)
int solution1(const std::vector<m_int> &numbers, const m_int &T) {
    int count = 0;
    for (int i = 0; i < numbers.size() - 3; i++) {
        for (int j = i + 1; j < numbers.size() - 2; j++) {
            for (int k = j + 1; k < numbers.size() - 1; k++) {
                for (int l = k + 1; l < numbers.size(); l++) {
                    count += numbers[i] + numbers[j] + numbers[k] + numbers[l] == T ? 1 : 0;
                }
            }
        }
    }
    return count;
}

// O(n^3)
int solution2(const std::vector<m_int> &numbers, const m_int &T) {
    int count = 0;

    for (int k = 2; k < numbers.size() - 1; k++) {
        std::unordered_map<m_int, int> L;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                m_int sum = numbers[i] + numbers[j];
                if (L.find(sum) == L.end()) {
                    L[sum] = 1;
                } else {
                    L[sum]++;
                }
            }
        }

        std::unordered_map<m_int, int> R;
        for (int l = k + 1; l < numbers.size(); l++) {
            m_int sum = numbers[k] + numbers[l];
            if (R.find(sum) == R.end()) {
                R[sum] = 1;
            } else {
                R[sum]++;
            }
        }

        for (auto &itemL : L) {
            auto itemR = R.find(T - itemL.first);
            if (itemR == R.end()) {
                continue;
            }

            count += itemL.second * itemR->second;
        }
    }

    return count;
}

#define BUFFER_SIZE 1000001

// O(n^2)
m_int solution3(const std::vector<m_int> &numbers, const m_int &T) {
    if (numbers.size() < 4) {
        return 0;
    }

    m_int count = 0;

    std::vector<m_int> L(T + 1, 0);
    for (int k = 2; k < numbers.size() - 1; k++) {
        for (int i = 0; i < k - 1; i++) {
            m_int sum = numbers[i] + numbers[k - 1];
            if (sum >= T) {
                continue;
            }
            L[sum]++;
        }

        for (int l = k + 1; l < numbers.size(); l++) {
            m_int sum = numbers[k] + numbers[l];
            if (sum >= T) {
                continue;
            }
            count += L[T - sum];
        }
    }

    return count;
}

// https://www.codechef.com/ZCOPRAC/problems/ZCO17001
// 10^10 = (10^3)^3*10 = 2^30 * 10
// 10^18 = (10^3)^6 = 2^60
int main() {
    std::ios_base::sync_with_stdio(false);

    int N, T;
    std::cin >> N >> T;

    std::vector<m_int> numbers(N, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> numbers[i];
    }

    std::cout << solution3(numbers, T) << std::endl;

    return 0;
}