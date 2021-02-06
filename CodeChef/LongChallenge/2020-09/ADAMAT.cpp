#include <cstdio>

int main() {
    int T, N;
    scanf("%d", &T);
    
    int matrix[80][80];
    
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        
        int operations = 0;
        
        for (int j = N - 1; j >= 0; j--) {
            int actual = operations % 2 == 0 ? matrix[0][j] : matrix[j][0] ;
            
            operations += actual != j + 1;
        }
        
        printf("%d\n", operations);
    }
    
    
    return 0;
}
