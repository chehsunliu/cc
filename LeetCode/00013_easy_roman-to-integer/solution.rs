impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let s = s.as_bytes();
        let mut prev_val = Solution::symbol_to_value(char::from(s[0]));
        let mut ans = prev_val;

        for (index, c) in s.iter().enumerate() {
            if index == 0 {
                continue;
            }

            let val = Solution::symbol_to_value(char::from(*c));
            ans += if val > prev_val { val - prev_val - prev_val } else { val };
            prev_val = val;
        }

        ans
    }

    fn symbol_to_value(symbol: char) -> i32 {
        match symbol {
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            _ => 1000,
        }
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(Solution::roman_to_int("III".to_string()), 3);
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::roman_to_int("IV".to_string()), 4);
    }

    #[test]
    fn example3() {
        assert_eq!(Solution::roman_to_int("IX".to_string()), 9);
    }

    #[test]
    fn example4() {
        assert_eq!(Solution::roman_to_int("LVIII".to_string()), 58);
    }

    #[test]
    fn example5() {
        assert_eq!(Solution::roman_to_int("MCMXCIV".to_string()), 1994);
    }
}
