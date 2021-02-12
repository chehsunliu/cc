mod leetcode;

impl Solution {
    pub fn convert_to_title(n: i32) -> String {
        let mut ans = String::new();
        let mut n = n;

        while n > 0 {
            ans.push(char::from('A' as u8 + ((n - 1) % 26) as u8));
            n = (n - 1) / 26;
        }

        ans.chars().rev().collect::<String>()
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(Solution::convert_to_title(1), String::from("A"));
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::convert_to_title(28), String::from("AB"));
    }

    #[test]
    fn example3() {
        assert_eq!(Solution::convert_to_title(701), String::from("ZY"));
    }

    #[test]
    fn example4() {
        assert_eq!(Solution::convert_to_title(27), String::from("AA"));
    }
}
