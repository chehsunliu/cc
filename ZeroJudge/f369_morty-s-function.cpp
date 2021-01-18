#include <cstdio>
#include <cmath>

#define BUFFER_SIZE 5
#define AMPLIFIER 1000000
//#define MY_DEBUG

typedef long double my_float;

void print_vector(my_float vec[BUFFER_SIZE], const int n) {
    for (int i = 0; i <= n; i++) {
        printf("%20.4Lf ", vec[i]);
    }
    printf("\n");
}

void print_matrix(my_float matrix[BUFFER_SIZE][BUFFER_SIZE], const int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%20.4Lf ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void initialize_identity(my_float identity[BUFFER_SIZE][BUFFER_SIZE], const int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            identity[i][j] = i == j ? AMPLIFIER : 0;
        }
    }
}

void initialize_x_matrix(my_float x_matrix[BUFFER_SIZE][BUFFER_SIZE], my_float x_vec[BUFFER_SIZE], const int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            x_matrix[i][j] = pow(x_vec[i], j);
        }
    }
}

void calculate_inverse_matrix(my_float x_matrix[BUFFER_SIZE][BUFFER_SIZE], my_float identity[BUFFER_SIZE][BUFFER_SIZE],
                              const int n) {
    for (int pivot = 0; pivot <= n; pivot++) {
        my_float pivot_value = x_matrix[pivot][pivot];
        for (int j = 0; j <= n; j++) {
            x_matrix[pivot][j] /= pivot_value;
            identity[pivot][j] /= pivot_value;
        }

        for (int i = 0; i <= n; i++) {
            if (i == pivot) {
                continue;
            }

            my_float factor = x_matrix[i][pivot];
            for (int j = 0; j <= n; j++) {
                x_matrix[i][j] -= x_matrix[pivot][j] * factor;
                identity[i][j] -= identity[pivot][j] * factor;
            }
        }
    }
}

void
calculate_c_vec(my_float identity[BUFFER_SIZE][BUFFER_SIZE], my_float y_vec[BUFFER_SIZE], my_float c_vec[BUFFER_SIZE],
                const int n) {
    for (int i = 0; i <= n; i++) {
        c_vec[i] = 0;
        for (int j = 0; j <= n; j++) {
            c_vec[i] += identity[i][j] * y_vec[j];
        }
    }
}

my_float calculate_f(const my_float k, my_float c_vec[BUFFER_SIZE], const int n) {
    my_float ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += pow(k, i) * c_vec[i] / AMPLIFIER / 100;
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);

    int n;
    my_float k;
    my_float c_vec[BUFFER_SIZE];
    my_float x_vec[BUFFER_SIZE];
    my_float y_vec[BUFFER_SIZE];
    my_float x_matrix[BUFFER_SIZE][BUFFER_SIZE];
    my_float identity[BUFFER_SIZE][BUFFER_SIZE];

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i <= n; i++) {
            scanf("%Lf", &x_vec[i]);
        }
        for (int i = 0; i <= n; i++) {
            scanf("%Lf", &y_vec[i]);
        }
        scanf("%Lf", &k);

        initialize_identity(identity, n);
        initialize_x_matrix(x_matrix, x_vec, n);

#ifdef MY_DEBUG
        print_matrix(x_matrix, n);
        print_matrix(identity, n);
#endif

        calculate_inverse_matrix(x_matrix, identity, n);
        calculate_c_vec(identity, y_vec, c_vec, n);

#ifdef MY_DEBUG
        print_matrix(x_matrix, n);
        print_matrix(identity, n);
        print_vector(c_vec, n);
#endif

        printf("%lld\n", (long long) calculate_f(k, c_vec, n));
    }

    return 0;
}
