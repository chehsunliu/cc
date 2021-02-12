#include <cstdio>
#include <algorithm>

int main() {
    int T, N;
    scanf("%d", &T);

    while (scanf("%d", &N) != EOF) {
        int count = 1, speed, front_speed;

        scanf("%d", &front_speed);
        for (int i = 1; i < N; i++) {
            scanf("%d", &speed);

            if (speed <= front_speed) {
                count++;
            }

            front_speed = std::min(front_speed, speed);
        }

        printf("%d\n", count);
    }

    return 0;
}