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

bool compare(const my_int &a, const my_int &b) {
    return a > b;
}

void solve(std::vector<std::vector<my_int>> &items, const int &total_weights) {
    std::sort(items[0].begin(), items[0].end(), compare);
    std::sort(items[1].begin(), items[1].end(), compare);

#ifdef MY_DEBUG
    print_vector(items[0]);
    print_vector(items[1]);
#endif

    my_int ans = 0;
    int indexes[2] = {0, 0};
    bool is_prev_unit_weight = false;
    int current_weight = 0;

    if (!items[0].empty()) {
        ans = items[0][indexes[0]];
        indexes[0]++;
        is_prev_unit_weight = true;
        current_weight++;
    }
    printf("%lld", ans);

    for (int weight = 2; weight <= total_weights; weight++) {
        if (is_prev_unit_weight) {
            if (weight == current_weight + 1) {
                if (indexes[0] < items[0].size() && indexes[1] < items[1].size()) {
                    if (items[0][indexes[0]] + items[0][indexes[0] - 1] > items[1][indexes[1]]) {
                        ans += items[0][indexes[0]];
                        indexes[0]++;
                        current_weight++;
                        is_prev_unit_weight = true;
                    } else {
                        ans = ans - items[0][indexes[0] - 1] + items[1][indexes[1]];
                        indexes[0]--;
                        indexes[1]++;
                        current_weight++;
                        is_prev_unit_weight = false;
                    }
                } else if (indexes[0] < items[0].size()) {
                    ans += items[0][indexes[0]];
                    indexes[0]++;
                    current_weight++;
                    is_prev_unit_weight = true;
                } else if (indexes[1] < items[1].size()) {
                    if (items[0][indexes[0] - 1] < items[1][indexes[1]]) {
                        ans = ans - items[0][indexes[0] - 1] + items[1][indexes[1]];
                        indexes[0]--;
                        indexes[1]++;
                        current_weight++;
                        is_prev_unit_weight = false;
                    }
                }
            } else {
                ans += items[1][indexes[1]];
                indexes[1]++;
                current_weight += 2;
                is_prev_unit_weight = false;
            }
        } else {
            if (weight == current_weight + 1) {
                if (indexes[0] < items[0].size()) {
                    ans += items[0][indexes[0]];
                    indexes[0]++;
                    current_weight++;
                    is_prev_unit_weight = true;
                }
            } else {
                ans += items[1][indexes[1]];
                indexes[1]++;
                current_weight += 2;
                is_prev_unit_weight = false;
            }
        }

        printf(" %lld", ans);
    }

    printf("\n");
}

// 10^9 * 10^5 = 10^14 = (10^3)^4 * 10^2 ~ 2^40 * 2^8
int main() {
    int n;
    scanf("%d", &n);

    int total_weights = 0;
    std::vector<std::vector<my_int>> items;
    items.emplace_back(std::vector<my_int>());
    items.emplace_back(std::vector<my_int>());

    for (int i = 0; i < n; i++) {
        int weight, value;
        scanf("%d %d", &weight, &value);
        items[weight - 1].push_back(value);

        total_weights += weight;
    }

    solve(items, total_weights);

    return 0;
}
