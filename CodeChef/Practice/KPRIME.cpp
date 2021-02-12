#include <cassert>
#include <cstdio>
#include <vector>

//#include "snippet/snippet.hpp"

typedef long long m_int;
#define MODULUS 1000000009
#define BUFFER_SIZE 100000

std::vector<int> build_primes() {
    int bound = BUFFER_SIZE;
    std::vector<bool> soe(bound + 1, true);
    soe[0] = false;
    soe[1] = false;

    int current_prime = 2;
    while (current_prime * current_prime <= bound) {
        for (int i = current_prime; i * current_prime < soe.size(); i++) {
            soe[i * current_prime] = false;
        }

        for (int i = current_prime + 1; i < soe.size(); i++) {
            if (soe[i]) {
                current_prime = i;
                break;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 0; i < soe.size(); i++) {
        if (soe[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int count_primes(int n, const std::vector<int> &primes, std::vector<int> &dp, int prime_index, bool prev_success) {
    if (n == 1) {
        return 1;
    }

    int count = 0;
    if (n % primes[prime_index] != 0) {
        for (int i = prime_index + 1; i < primes.size(); i++) {
            if (n % primes[i] == 0) {
                prime_index = i;
                break;
            }
        }
        count += prev_success;
    }

    dp[n] = dp[n] > 0 ? dp[n] : count_primes(n / primes[prime_index], primes, dp, prime_index, true);
    count += dp[n];

    return count;
}

// 10^10 = (10^3)^3*10 = 2^30 * 10
int main() {
    int T;
    scanf("%d", &T);

    std::vector<int> primes = build_primes();
    std::vector<int> dp(BUFFER_SIZE + 1, 0);
    std::vector<std::vector<int>> dp_acc;

    for (int n = 2; n <= BUFFER_SIZE; n++) {
        count_primes(n, primes, dp, 0, false);
    }

    for (int i = 1; i <= 5; i++) {
        std::vector<int> tmp(BUFFER_SIZE + 1, 0);
        for (int n = 2; n <= BUFFER_SIZE; n++) {
            if (dp[n] == i) {
                tmp[n] = tmp[n - 1] + 1;
            } else {
                tmp[n] = tmp[n - 1];
            }
        }
        dp_acc.push_back(tmp);
    }

    for (int t = 0; t < T; t++) {
        int A, B, K;
        scanf("%d %d %d", &A, &B, &K);

        int ans = dp_acc[K - 1][B] - dp_acc[K - 1][A] + (dp[A] == K ? 1 : 0);
        printf("%d\n", ans);
    }

    return 0;
}