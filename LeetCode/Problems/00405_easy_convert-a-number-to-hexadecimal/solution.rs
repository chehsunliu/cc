mod leetcode;

impl Solution {
    pub fn to_hex(num: i32) -> String {
        let mut num: u32 = num as u32;
        let mut ans = String::new();

        while num != 0 {
            let digit = match num % 16 {
                x if x < 10 => char::from('0' as u8 + x as u8),
                x => char::from('a' as u8 + (x - 10) as u8),
            };
            ans.push(digit);
            num /= 16;
        }

        if ans.is_empty() {
            ans.push('0');
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
        assert_eq!(Solution::to_hex(26), "1a".to_string());
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::to_hex(-1), "ffffffff".to_string());
    }
}
