#include <cstdio>

#include <algorithm>
#include <vector>

//#define MY_DEBUG

#ifdef MY_DEBUG
void print_vector(const std::vector<int> nums) {
    for (auto &num : nums) {
        printf("%d ", num);
    }
    printf("\n");
}
#endif

typedef long long my_int;

bool compare(const my_int &a, const my_int &b) { return a > b; }

void solve_even(const std::vector<my_int> &items1, const std::vector<my_int> &items2, std::vector<my_int> &answers,
                const int &total_weights) {
    int index1 = 0;
    int index2 = 0;
    my_int current_value = 0;
    for (int w = 2; w <= total_weights; w += 2) {
        if (index1 < items1.size() && index2 < items2.size()) {
            my_int v1 = index1 + 1 < items1.size() ? items1[index1] + items1[index1 + 1] : items1[index1];
            my_int v2 = items2[index2];
            if (v1 > v2) {
                index1 += index1 + 1 < items1.size() ? 2 : 1;
                current_value += v1;
            } else {
                index2++;
                current_value += v2;
            }
        } else if (index1 < items1.size()) {
            my_int v1 = index1 + 1 < items1.size() ? items1[index1] + items1[index1 + 1] : items1[index1];
            index1 += index1 + 1 < items1.size() ? 2 : 1;
            current_value += v1;
        } else {
            my_int v2 = items2[index2];
            index2++;
            current_value += v2;
        }

        answers[w] = current_value;
    }
}

void solve_odd(const std::vector<my_int> &items1, const std::vector<my_int> &items2, std::vector<my_int> &answers,
               const int &total_weights) {
    int index1 = 0;
    int index2 = 0;
    my_int current_value = 0;

    if (!items1.empty()) {
        current_value += items1[index1];
        index1++;
        answers[1] = current_value;
    } else {
        answers[1] = 0;
    }

    for (int w = 3; w <= total_weights; w += 2) {
        if (index1 < items1.size() && index2 < items2.size()) {
            my_int v1 = index1 + 1 < items1.size() ? items1[index1] + items1[index1 + 1] : items1[index1];
            my_int v2 = items2[index2];
            if (v1 > v2) {
                index1 += index1 + 1 < items1.size() ? 2 : 1;
                current_value += v1;
            } else {
                index2++;
                current_value += v2;
            }
        } else if (index1 < items1.size()) {
            my_int v1 = index1 + 1 < items1.size() ? items1[index1] + items1[index1 + 1] : items1[index1];
            index1 += index1 + 1 < items1.size() ? 2 : 1;
            current_value += v1;
        } else {
            my_int v2 = items2[index2];
            index2++;
            current_value += v2;
        }

        answers[w] = current_value;
    }
}

void solve(std::vector<my_int> &items1, std::vector<my_int> &items2, const int &total_weights) {
    std::sort(items1.begin(), items1.end(), compare);
    std::sort(items2.begin(), items2.end(), compare);

#ifdef MY_DEBUG
    print_vector(items1);
    print_vector(items2);
#endif

    std::vector<my_int> answers(total_weights + 1, 0);
    solve_even(items1, items2, answers, total_weights);
    solve_odd(items1, items2, answers, total_weights);

    for (int w = 1; w <= total_weights; w++) {
        printf("%2lld ", answers[w]);
    }
    printf("\n");
}

// 10^9 * 10^5 = 10^14 = (10^3)^4 * 10^2 ~ 2^40 * 2^8
int main() {
    int n;
    scanf("%d", &n);

    int total_weights = 0;
    std::vector<my_int> items1;
    std::vector<my_int> items2;

    for (int i = 0; i < n; i++) {
        int weight, value;
        scanf("%d %d", &weight, &value);

        if (weight == 1) {
            items1.push_back(value);
        } else {
            items2.push_back(value);
        }

        total_weights += weight;
    }

    solve(items1, items2, total_weights);

    return 0;
}
