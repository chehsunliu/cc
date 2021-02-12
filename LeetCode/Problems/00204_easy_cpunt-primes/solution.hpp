#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <cmath>

#include <algorithm>
#include <vector>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class Solution {
  public:
    bool is_prime(int n, vector<int> &primes) {
        if (n == 2 || n == 3) {
            return true;
        } else if (n == 0 || n == 1) {
            return false;
        }

        int bound = sqrt(n) + 1;
        for (int i = 0; i < primes.size(); i++) {
            if (n % primes[i] == 0) {
                return false;
            } else if (primes[i] > bound) {
                break;
            }
        }

        primes.push_back(n);
        return true;
    }

    int countPrimes(int n) {
        vector<int> primes;
        primes.push_back(2);
        primes.push_back(3);

        int count = 0;

        for (int i = 0; i < n; i++) {
            count += is_prime(i, primes);
        }

        return count;
    }
};

} // namespace wb

#endif
