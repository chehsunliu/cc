#ifndef __CODEBOOK_PRIME_H__
#define __CODEBOOK_PRIME_H__

#include <set>
#include <vector>

namespace codebook {
namespace prime {

std::vector<bool> constructSoETable(const int upperBound) {
    // https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

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

    return table;
}

std::vector<int> createPrimes(const int upperBound) {
    std::vector<bool> table = constructSoETable(upperBound);
    std::vector<int> primes;

    for (int i = 0; i < table.size(); i++) {
        if (table[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

std::set<int> createPrimeSet(const int upperBound) {
    std::vector<bool> table = constructSoETable(upperBound);
    std::set<int> primes;

    for (int i = 0; i < table.size(); i++) {
        if (table[i]) {
            primes.insert(i);
        }
    }

    return primes;
}

}  // namespace prime
}  // namespace codebook

#endif