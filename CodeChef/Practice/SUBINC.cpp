#include <cstdio>

//#include "snippet/snippet.hpp"

#define BUFFER_SIZE 100001

typedef unsigned long long my_int;

my_int calculate(my_int n) {
    return n == 1 ? 1 : n * (n + 1) / 2;
}

my_int solve(const my_int A[BUFFER_SIZE], int N) {
    int base_index = 0;
    my_int count = 0;
    for (int i = 1; i < N; i++) {
        if (A[i - 1] > A[i]) {
            count += calculate(i - base_index);
            base_index = i;
        }
    }
    count += calculate(N - base_index);
    return count;
}

int main() {
    int T;
    int N;
    my_int A[BUFFER_SIZE];

    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%llu", &A[i]);
        }

        printf("%llu\n", solve(A, N));
    }

    return 0;
}