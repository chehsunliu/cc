#include <cstdio>
#include <algorithm>

#ifndef RUN_IN_GTEST

// 2^32 == (2^10)^3 * 4 ~= 10^9 * 4
// 2^64 == (2^10)^6 * 16 ~= 10^18 * 16
int main(int argc, char *args[]) {
    int T, N;
    scanf("%d", &T);

    int A[100001];

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        std::sort(A, A + N);

        int current = A[N - 1];
        int operations = 0;

        for (int i = N - 2; i >= 0; i--) {
            if (current != A[i]) {
                current = A[i];
                operations++;
            }
        }

        operations += A[0] != 0 ? 1 : 0;

        printf("%d\n", operations);
    }

    return 0;
}

#endif