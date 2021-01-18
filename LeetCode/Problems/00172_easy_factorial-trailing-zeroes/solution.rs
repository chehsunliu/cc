mod leetcode;

impl Solution {
    pub fn trailing_zeroes(n: i32) -> i32 {
        let mut ans = 0;
        let mut power = 5;

        while power <= n {
            ans += n / power;
            power *= 5;
        }

        ans
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(Solution::trailing_zeroes(3), 0);
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::trailing_zeroes(5), 1);
    }

    #[test]
    fn example3() {
        assert_eq!(Solution::trailing_zeroes(0), 0);
    }
}
