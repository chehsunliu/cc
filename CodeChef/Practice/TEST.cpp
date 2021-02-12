#include <cstdio>

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        if (n == 42) {
            break;
        }

        printf("%d\n", n);
    };

    return 0;
}