use std::cmp::max;
use std::fmt::Write as jizz;

impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let mut ans = String::new();
        let max_length = max(a.len(), b.len());
        let mut carry = 0;

        for i in 0..max_length {
            let mut value = carry;

            let a_index = a.len() as i32 - i as i32 - 1;
            if a_index >= 0 && a.chars().nth(a_index as usize).unwrap() == '1' {
                value += 1;
            }

            let b_index = b.len() as i32 - i as i32 - 1;
            if b_index >= 0 && b.chars().nth(b_index as usize).unwrap() == '1' {
                value += 1;
            }

            carry = value / 2;
            value %= 2;

            ans.write_char(if value > 0 { '1' } else { '0' });
        }

        if carry > 0 {
            ans.write_char('1');
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
        assert_eq!(Solution::add_binary("11".to_string(), "1".to_string()), "100".to_string());
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::add_binary("1010".to_string(), "1011".to_string()), "10101".to_string());
    }
}
