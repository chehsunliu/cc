#include <cstdio>
#include <cmath>

double area(const double coefficients[11], int n, double a, double b) {
    double ans = 0;
    for (int i = n; i >= 0; i--) {
        ans += coefficients[i] * (pow(b, i + 1) - pow(a, i + 1)) / (i + 1);
    }
    return M_PI * ans;
}

int main() {
    int t;
    int n;
    int coefficients[6];
    int a, b;

    scanf("%d", &t);

    while (scanf("%d", &n) != EOF) {
        for (int i = n; i >= 0; i--) {
            scanf("%d", &coefficients[i]);
        }

        scanf("%d %d", &a, &b);

        double coefficients2[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                coefficients2[i + j] += coefficients[i] * coefficients[j];
            }
        }

        printf("%.2f\n", area(coefficients2, n * 2, a, b));
    }

    return 0;
}
