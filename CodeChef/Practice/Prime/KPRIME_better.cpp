#include <cassert>
#include <cstdio>
#include <vector>

//#include "snippet/snippet.hpp"

typedef long long m_int;
#define BUFFER_SIZE 100001

void build_by_soe(std::vector<bool> &is_prime, std::vector<int> &table) {
    for (int i = 2; i < is_prime.size(); i++) {
        if (!is_prime[i]) {
            continue;
        }

        table[i]++;
        for (int j = 2; i * j < is_prime.size(); j++) {
            is_prime[i * j] = false;
            table[i * j]++;
        }
    }
}

void build_acc(const std::vector<int> &table, std::vector<std::vector<int>> &acc) {
    for (int k = 1; k <= 6; k++) {
        std::vector<int> tmp(table.size(), 0);

        for (int i = 2; i < table.size(); i++) {
            if (table[i] == k) {
                tmp[i] = tmp[i - 1] + 1;
            } else {
                tmp[i] = tmp[i - 1];
            }
        }

        acc.push_back(tmp);
    }
}

// 10^10 = (10^3)^3*10 = 2^30 * 10
int main() {
    int T;
    scanf("%d", &T);

    std::vector<bool> is_prime(BUFFER_SIZE, true);
    std::vector<int> table(is_prime.size(), 0);
    build_by_soe(is_prime, table);

    std::vector<std::vector<int>> acc;
    build_acc(table, acc);

    for (int t = 0; t < T; t++) {
        int A, B, K;
        scanf("%d %d %d", &A, &B, &K);

        int count = acc[K - 1][B] - acc[K - 1][A] + (table[A] == K ? 1 : 0);
        printf("%d\n", count);
    }

    return 0;
}