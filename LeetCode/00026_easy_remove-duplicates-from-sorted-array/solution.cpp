#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int pos = 1;
        int prev_value = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == prev_value) {

            } else {
                nums[pos] = nums[i];
                prev_value = nums[i];
                pos += 1;
            }
        }

        return pos;
    }
};

int main() {
    printf("Hello!\n");
    return 0;
}
