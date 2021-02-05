#include <cstdio>
#include <algorithm>

#define BUFFER_SIZE 1000000

int main() {
    int N;
    long budgets[BUFFER_SIZE];

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            scanf("%ld", &budgets[i]);
        }

        std::sort(budgets, budgets + N);
        long revenue = 0;

        for (int i = 0; i < N; i++) {
            revenue = std::max(revenue, (N - i) * budgets[i]);
        }

        printf("%ld\n", revenue);
    }

    return 0;
}