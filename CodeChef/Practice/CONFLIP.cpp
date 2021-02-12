#include <cstdio>


#ifndef RUN_IN_GTEST


// 2^32 == (2^10)^3 * 4 ~= 10^9 * 4
// 2^64 == (2^10)^6 * 16 ~= 10^18 * 16
int main(int argc, char *args[]) {
    int T, G;
    scanf("%d", &T);

    while (scanf("%d", &G) != EOF) {
        int I, N, Q, ans;

        for (int i = 0; i < G; i++) {
            scanf("%d %d %d", &I, &N, &Q);

            if (N % 2 == 0) {
                ans = N / 2;
            } else {
                int heads = I == 1 ? N / 2 : N - N / 2;
                ans = Q == 1 ? heads : N - heads;
            }

            printf("%d\n", ans);
        }
    }

    return 0;
}

#endif