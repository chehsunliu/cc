#include <iostream>

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

    m_int N, M, A;
    std::cin >> N >> M >> A;

    m_int edgeN = N / A + (N % A > 0);
    m_int edgeM = M / A + (M % A > 0);
    std::cout << edgeN * edgeM << std::endl;

    return 0;
}