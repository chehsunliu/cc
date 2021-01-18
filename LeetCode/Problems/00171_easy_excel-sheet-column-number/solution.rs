mod leetcode;

impl Solution {
    pub fn title_to_number(s: String) -> i32 {
        let mut ans = 0;
        let mut power = 1;

        for (i, c) in s.chars().rev().enumerate() {
            ans += (c as i32 - 'A' as i32 + 1) * power;
            power *= 26;
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
        assert_eq!(Solution::title_to_number("A".to_string()), 1);
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::title_to_number("AB".to_string()), 28);
    }

    #[test]
    fn example3() {
        assert_eq!(Solution::title_to_number("ZY".to_string()), 701);
    }
}
