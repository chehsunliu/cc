#include <algorithm>
#include <iostream>
#include <vector>

//#include "snippet/snippet.hpp"

typedef long long cc_int;

#ifdef __SIZEOF_INT128__
typedef __int128 int128;
#endif

class Frog {
  public:
    int weight;
    int movement;
    int position;

    Frog() : weight(0), movement(0), position(0) {}
    Frog(int weight, int movement, int position) : weight(weight), movement(movement), position(position) {}

    friend std::ostream &operator<<(std::ostream &os, const Frog &frog) {
        os << "w:" << frog.weight << "/p:" << frog.position;
        return os;
    }
};

bool isValid(std::vector<Frog> &frogs) {
    for (int i = 0; i < frogs.size() - 1; i++) {
        if (frogs[i].weight > frogs[i + 1].weight || frogs[i].position >= frogs[i + 1].position) {
            return false;
        }
    }

    return true;
}

int solve(std::vector<Frog> &frogs) {
    int hits = 0;

    while (!isValid(frogs)) {
        for (int i = 0; i < frogs.size() - 1; i++) {
            if (frogs[i].position > frogs[i + 1].position) {
                std::swap(frogs[i], frogs[i + 1]);
            } else if (frogs[i].weight > frogs[i + 1].weight) {
                frogs[i].position += frogs[i].movement;
                std::swap(frogs[i], frogs[i + 1]);
                hits++;
            } else if (frogs[i].position == frogs[i + 1].position) {
                frogs[i + 1].position += frogs[i + 1].movement;
                hits++;
            }
        }
    }

    return hits;
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

        std::vector<int> weights(N);
        for (int i = 0; i < N; i++) {
            std::cin >> weights[i];
        }

        std::vector<int> movements(N);
        for (int i = 0; i < N; i++) {
            std::cin >> movements[i];
        }

        std::vector<Frog> frogs;
        frogs.reserve(N);
        for (int i = 0; i < N; i++) {
            frogs.emplace_back(weights[i], movements[i], i);
        }

        std::cout << solve(frogs) << std::endl;
    }

    return 0;
}