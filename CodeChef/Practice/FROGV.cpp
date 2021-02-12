#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <unordered_map>
#include <vector>

//#include "snippet/snippet.hpp"

typedef long long m_int;
#define BUFFER_SIZE 100001

class Frog {
  public:
    int x;
    int index;

    Frog() : x(0), index(0) {}
};

bool compare(const Frog &f1, const Frog &f2) { return f1.x < f2.x; }

std::vector<Frog> load_frogs(const int &N) {
    std::vector<Frog> frogs(N);
    for (int i = 0; i < frogs.size(); i++) {
        scanf("%d", &frogs[i].x);
        frogs[i].index = i;
    }

    return frogs;
}

std::unordered_map<int, int> organize_frogs(std::vector<Frog> &frogs) {
    std::sort(frogs.begin(), frogs.end(), compare);

    std::unordered_map<int, int> index_map;
    for (int i = 0; i < frogs.size(); i++) {
        index_map.insert(std::make_pair(frogs[i].index, i));
    }

    return index_map;
}

std::vector<int> build_marks(const std::vector<Frog> &frogs, const int &K) {
    int mark = 0;
    std::vector<int> marks(frogs.size(), mark);
    for (int i = 1; i < marks.size(); i++) {
        if (frogs[i].x  - frogs[i - 1].x > K) {
            mark++;
        }
        marks[i] = mark;
    }

    return marks;
}

// 10^10 = (10^3)^3*10 = 2^30 * 10
int main() {
    int N, K, P;
    scanf("%d %d %d", &N, &K, &P);

    std::vector<Frog> frogs = load_frogs(N);
    std::unordered_map<int, int> index_map = organize_frogs(frogs);
    std::vector<int> marks = build_marks(frogs, K);

    for (int p = 0; p < P; p++) {
        int A, B;
        scanf("%d %d", &A, &B);
        int index_a = index_map.find(A - 1)->second;
        int index_b = index_map.find(B - 1)->second;

        if (marks[index_a] == marks[index_b]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}