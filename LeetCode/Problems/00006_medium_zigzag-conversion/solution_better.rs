mod leetcode;

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 {
            return s;
        }

        let mut answers = vec!["".to_string(); num_rows as usize];

        let mut row: i32 = 0;
        let mut step: i32 = 1;

        for c in s.chars() {
            answers[row as usize].push(c);

            if row == 0 {
                step = 1;
            } else if row == num_rows - 1 {
                step = -1;
            }

            row += step;
        }

        return answers.join("");
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn gg1() {
        assert_eq!(
            Solution::convert("PAYPALISHIRING".to_string(), 3),
            "PAHNAPLSIIGYIR".to_string()
        );
    }

    #[test]
    fn gg2() {
        assert_eq!(
            Solution::convert("PAYPALISHIRING".to_string(), 4),
            "PINALSIGYAHRPI".to_string()
        );
    }

    #[test]
    fn gg3() {
        assert_eq!(Solution::convert("A".to_string(), 1), "A".to_string());
    }

    #[test]
    fn gg4() {
        assert_eq!(Solution::convert("AB".to_string(), 1), "AB".to_string());
    }
}
