#include <cstdio>
#include <cstring>

#define BUFFER_SIZE 1001

int main() {
    int T;

    scanf("%d", &T);
    char S[BUFFER_SIZE];

    int freq0[26];
    int freq1[26];

    while (scanf("%s", S) != EOF) {
        int S_length = strlen(S);

        for (int i = 0; i < 26; i++) {
            freq0[i] = freq1[i] = 0;
        }

        for (int i = 0; i < S_length / 2; i++) {
            freq0[S[i] - 'a']++;
            freq1[S[S_length - i - 1] - 'a']++;
        }

        bool same = true;
        for (int i = 0; i < 26; i++) {
            same &= freq0[i] == freq1[i];
        }

        if (same) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}