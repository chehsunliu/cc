mod leetcode;

impl Solution {
    fn convert(num: i32, digits: i32) -> String {
        let (symbol1, symbol5, symbol10) = match digits {
            0 => ('I', 'V', 'X'),
            1 => ('X', 'L', 'C'),
            2 => ('C', 'D', 'M'),
            _ => ('M', '_', '_'),
        };

        let mut tmp = String::new();

        if num <= 3 {
            for _ in 0..num {
                tmp.push(symbol1)
            }
        } else if num == 4 {
            tmp.push(symbol1);
            tmp.push(symbol5);
        } else if num == 5 {
            tmp.push(symbol5);
        } else if num > 5 && num <= 8 {
            tmp.push(symbol5);
            for _ in 0..(num - 5) {
                tmp.push(symbol1);
            }
        } else {
            tmp.push(symbol1);
            tmp.push(symbol10);
        }

        tmp
    }

    pub fn int_to_roman(num: i32) -> String {
        let mut digits = 0;
        let mut num = num;
        let mut ans = String::new();

        while num != 0 {
            ans = Solution::convert(num % 10, digits) + &*ans;
            num /= 10;
            digits += 1;
        }

        ans
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn gg1() {
        assert_eq!(Solution::int_to_roman(3), "III".to_string());
    }

    #[test]
    fn gg2() {
        assert_eq!(Solution::int_to_roman(4), "IV".to_string());
    }

    #[test]
    fn gg3() {
        assert_eq!(Solution::int_to_roman(9), "IX".to_string());
    }

    #[test]
    fn gg4() {
        assert_eq!(Solution::int_to_roman(58), "LVIII".to_string());
    }

    #[test]
    fn gg5() {
        assert_eq!(Solution::int_to_roman(1994), "MCMXCIV".to_string());
    }
}
