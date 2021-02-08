#include <algorithm>
#include <iostream>
#include <vector>

#include <snippet/snippet.hpp>

typedef unsigned long long m_int;
typedef __int128 int128;


// https://www.codechef.com/MAY17/problems/CHEFCODE
// 10^10 = (10^3)^3*10 = 2^30 * 10
// 10^18 = (10^3)^6 = 2^60
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> a({1, 2});
    snippet::io::print_vector(a);

    return 0;
}