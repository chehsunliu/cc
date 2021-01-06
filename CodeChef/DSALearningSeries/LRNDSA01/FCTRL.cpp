#include <cstdio>


#ifndef RUN_IN_GTEST

int count_zeros(int N) {
    int base = 5, count = 0;

    while (base <= N) {
        count += N / base;
        base *= 5;
    }

    return count;
}

// 2^32 == (2^10)^3 * 4 ~= 10^9 * 4
// 2^64 == (2^10)^6 * 16 ~= 10^18 * 16
int main(int argc, char *args[]) {
    int T, N;
    scanf("%d", &T);

    while (scanf("%d", &N) != EOF) {
        printf("%d\n", count_zeros(N));
    }

    return 0;
}

#endif