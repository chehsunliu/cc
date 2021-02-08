#ifndef __SNIPPET_PRIME_H__
#define __SNIPPET_PRIME_H__

#include <vector>

namespace snippet {
namespace prime {

std::vector<int> generatePrimesBySieveOfEratosthenes(const int upperBound) {
    std::vector<bool> table(upperBound + 1, true);
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

    std::vector<int> primes;

    for (int i = 0; i < table.size(); i++) {
        if (table[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

} // namespace prime
} // namespace snippet

#endif