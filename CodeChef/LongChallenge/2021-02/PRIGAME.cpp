#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

//#include "snippet/snippet.hpp"

typedef unsigned long long cc_int;

#ifdef __SIZEOF_INT128__
typedef __int128 int128;
#endif

std::vector<int> primes;

void init_primes_by_sieve_of_eratosthenes() {
    std::vector<bool> table(1000001, true);
    table[0] = false;
    table[1] = false;

    int prime = 2;
    while (prime * prime < table.size()) {
        for (int i = prime * prime; i < table.size(); i += prime) {
            table[i] = false;
        }

        for (int i = prime + 1; i < table.size(); i++) {
            if (table[i]) {
                prime = i;
                break;
            }
        }
    }

    for (int i = 0; i < table.size(); i++) {
        if (table[i]) {
            primes.push_back(i);
        }
    }
}

bool solve(int X, int Y) {
    int distinct_primes_x = std::upper_bound(primes.begin(), primes.end(), X) - primes.begin();
    return Y >= distinct_primes_x;
}

// 10^10 = (10^3)^3*10 = 2^30 * 10
// 10^18 = (10^3)^6 = 2^60
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    init_primes_by_sieve_of_eratosthenes();

    for (int t = 0; t < T; t++) {
        int X, Y;
        std::cin >> X >> Y;

        if (solve(X, Y)) {
            std::cout << "Chef\n";
        } else {
            std::cout << "Divyam\n";
        }
    }

    return 0;
}