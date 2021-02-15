#include <algorithm>
#include <iostream>
#include <vector>

//#include "snippet/snippet.hpp"

typedef unsigned long long m_int;

#ifdef __SIZEOF_INT128__
typedef __int128 int128;
#endif

// 10^10 = (10^3)^3*10 = 2^30 * 10
// 10^18 = (10^3)^6 = 2^60
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 10; i >= 1; i--) {
        if (N % i == 0) {
            std::cout << i << std::endl;
            break;
        }
    }

    return 0;
}