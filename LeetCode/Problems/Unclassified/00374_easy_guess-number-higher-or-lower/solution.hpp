class Solution {
  public:
    int guessNumber(int n) {
        long long left = 1;
        long long right = n;

        while (left <= right) {
            long long middle = (left + right) / 2;
            int result = guess(middle);

            if (result == 0) {
                return middle;
            } else if (result == -1) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return left;
    }
};