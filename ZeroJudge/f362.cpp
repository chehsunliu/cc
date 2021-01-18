#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

int main() {
    double e;

    while (scanf("%lf", &e) != EOF) {
        std::vector<double> possible_answers;
        double ac, ac_sqrt, p;

        ac = 1 - 4 * e;
        if (ac >= 0) {
            ac_sqrt = sqrt(ac);
            p = (1 + ac_sqrt) / 2;
            if (p > e) {
                possible_answers.push_back(p);
            }
            p = (1 - ac_sqrt) / 2;
            if (p > e) {
                possible_answers.push_back(p);
            }
        }

        ac = 1 + 4 * e;
        if (ac >= 0) {
            ac_sqrt = sqrt(ac);
            p = (-1 + ac_sqrt) / 2;
            if (p < e) {
                possible_answers.push_back(p);
            }
            p = (-1 - ac_sqrt) / 2;
            if (p < e) {
                possible_answers.push_back(p);
            }
        }

        std::sort(possible_answers.begin(), possible_answers.end());
        std::vector<double> answers;

        for (int i = 0; i < possible_answers.size(); i++) {
            if (i > 0) {
                if (possible_answers[i - 1] == possible_answers[i]) {
                    continue;
                }

                char buf0[10];
                char buf1[10];
                sprintf(buf0, "%.2f", possible_answers[i - 1]);
                sprintf(buf1, "%.2f", possible_answers[i]);
                if (!strcmp(buf0, buf1)) {
                    continue;
                }
            }
            if (possible_answers[i] <= 0) {
                continue;
            }
            answers.push_back(possible_answers[i]);
        }

        if (answers.empty()) {
            printf("NULL\n");
            continue;
        }

        for (double answer : answers) {
            printf("%.2f ", answer);
        }
        printf("\n");
    }

    return 0;
}
