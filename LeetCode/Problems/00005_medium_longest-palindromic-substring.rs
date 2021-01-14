use std::cmp::min;
use std::str::from_utf8;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let s = s.as_bytes();
        let mut ans: (usize, usize) = (0, 0);

        for i in 0..s.len() {
            let bound = min(i - 0, s.len() - 1 - i);

            for j in 0..(bound + 1) {
                if s[i + j] != s[i - j] {
                    let local_ans = (i + 1 - j, i + j - 1);
                    if local_ans.1 - local_ans.0 > ans.1 - ans.0 {
                        ans = local_ans;
                    }
                    break;
                } else if j == bound {
                    let local_ans = (i - j, i + j);
                    if local_ans.1 - local_ans.0 > ans.1 - ans.0 {
                        ans = local_ans;
                    }
                    break;
                }
            }
        }

        for i in 0..(s.len() - 1) {
            if s[i] != s[i + 1] {
                continue;
            }

            let bound = min(i - 0, s.len() - 1 - i - 1);

            for j in 0..(bound + 1) {
                if s[i + 1 + j] != s[i - j] {
                    let local_ans = (i + 1 - j, i + j);
                    if local_ans.1 - local_ans.0 > ans.1 - ans.0 {
                        ans = local_ans;
                    }
                    break;
                } else if j == bound {
                    let local_ans = (i - j, i + j + 1);
                    if local_ans.1 - local_ans.0 > ans.1 - ans.0 {
                        ans = local_ans;
                    }
                    break;
                }
            }
        }

        from_utf8(&s[ans.0..(ans.1 + 1)]).unwrap().to_string()
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(
            Solution::longest_palindrome("babad".to_string()),
            "bab".to_string()
        );
    }

    #[test]
    fn example2() {
        assert_eq!(
            Solution::longest_palindrome("cbbd".to_string()),
            "bb".to_string()
        );
    }

    #[test]
    fn example3() {
        assert_eq!(
            Solution::longest_palindrome("a".to_string()),
            "a".to_string()
        );
    }

    #[test]
    fn example4() {
        assert_eq!(
            Solution::longest_palindrome("ac".to_string()),
            "a".to_string()
        );
    }

    #[test]
    fn example5() {
        assert_eq!(
            Solution::longest_palindrome("aba".to_string()),
            "aba".to_string()
        );
    }
}
