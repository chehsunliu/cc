#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

//#include "snippet/snippet.hpp"

typedef unsigned long long cc_int;

#ifdef __SIZEOF_INT128__
typedef __int128 int128;
#endif

cc_int solve(std::vector<std::set<std::string>> &funny_words) {
    cc_int count = 0;

    for (int c0 = 0; c0 < funny_words.size(); c0++) {
        for (int c1 = c0 + 1; c1 < funny_words.size(); c1++) {
            std::set<std::string> &w0 = funny_words[c0];
            std::set<std::string> &w1 = funny_words[c1];

            std::vector<std::string> a0(w0.size() + w1.size());
            auto it0 = std::set_difference(w0.begin(), w0.end(), w1.begin(), w1.end(), a0.begin());
            a0.resize(it0 - a0.begin());

            std::vector<std::string> a1(w0.size() + w1.size());
            auto it1 = std::set_difference(w1.begin(), w1.end(), w0.begin(), w0.end(), a1.begin());
            a1.resize(it1 - a1.begin());

            count += a0.size() * a1.size();
        }
    }

    return count * 2;
}

// 10^10 = (10^3)^3*10 = 2^30 * 10
// 10^18 = (10^3)^6 = 2^60
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        std::cin >> N;

        std::vector<std::set<std::string>> funny_words(26);
        for (int i = 0; i < N; i++) {
            std::string tmp;
            std::cin >> tmp;
            funny_words[tmp[0] - 'a'].insert(tmp.substr(1));
        }

        std::cout << solve(funny_words) << std::endl;
    }

    return 0;
}