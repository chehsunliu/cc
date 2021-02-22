#include <algorithm>
#include <iostream>
#include <random>

//#include "codebook/codebook.hpp"

void solveRecursively(std::string &s, int left, int right, std::mt19937 &mt) {
    if (left >= right) {
        return;
    }

    int l = left;
    int r = right;

    std::uniform_int_distribution<int> distribution(l, r);
    int m = distribution(mt);

    char cmpResult;

    std::swap(s[m], s[l]);
    while (l < r) {
        std::cout << "? " << s[l] << " " << s[l + 1] << std::endl;
        std::cin >> cmpResult;

        if (cmpResult == '>') {
            std::swap(s[l], s[l + 1]);
            l++;
        } else {
            std::swap(s[l + 1], s[r]);
            r--;
        }
    }

    solveRecursively(s, left, l - 1, mt);
    solveRecursively(s, l + 1, right, mt);
}

// 10^10 = (10^3)^3*10 = 2^30 * 10
// 10^18 = (10^3)^6 = 2^60
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::random_device randomDevice;
    std::mt19937 mt(randomDevice());

    int n, q;
    std::cin >> n >> q;

    std::string s(n, 'A');
    for (int i = 0; i < n; i++) {
        s[i] = 'A' + i;
    }

    solveRecursively(s, 0, n - 1, mt);

    std::cout << "! " << s << "\n";

    return 0;
}

// A B C D E
// 1 2 5 4 3
