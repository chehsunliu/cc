#include <cstdio>
#include <cstring>

#define BUFFER_SIZE 64

int main() {
    int n, T;

    scanf("%d", &T);
    char buffer[BUFFER_SIZE];

    for (int t = 0; t < T; t++) {
        scanf("%s", buffer);
        int length = strlen(buffer);

        bool hit_first_non_zero = false;
        for (int i = length - 1; i >= 0; i--) {
            char c = buffer[i];
            hit_first_non_zero = c != '0' || hit_first_non_zero;

            if (!hit_first_non_zero && i != 0) {
                continue;
            }

            printf("%c", c);
        }
        printf("\n");
    }

    return 0;
}