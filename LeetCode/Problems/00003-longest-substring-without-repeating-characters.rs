use std::cmp::max;
use std::collections::HashMap;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let s = s.as_bytes();
        let mut history = HashMap::new();
        let mut current_length: i32 = 0;
        let mut longest_length: i32 = 0;

        for (i, c) in s.iter().enumerate() {
            match history.insert(*c, i) {
                None => {
                    current_length += 1;
                }
                Some(prev_i) => {
                    longest_length = max(longest_length, current_length);

                    for j in (i - current_length as usize)..(prev_i) {
                        history.remove(&s[j]);
                    }

                    current_length -= prev_i as i32 - i as i32 + current_length;
                }
            }
        }

        max(longest_length, current_length)
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(
            Solution::length_of_longest_substring("abcabcbb".to_string()),
            3
        );
    }

    #[test]
    fn example2() {
        assert_eq!(
            Solution::length_of_longest_substring("bbbbb".to_string()),
            1
        );
    }

    #[test]
    fn example3() {
        assert_eq!(
            Solution::length_of_longest_substring("pwwkew".to_string()),
            3
        );
    }

    #[test]
    fn example4() {
        assert_eq!(Solution::length_of_longest_substring("".to_string()), 0);
    }

    #[test]
    fn example5() {
        assert_eq!(Solution::length_of_longest_substring("dvdf".to_string()), 3);
    }

    #[test]
    fn example6() {
        assert_eq!(
            Solution::length_of_longest_substring("abcdefgc1234".to_string()),
            9
        );
    }

    #[test]
    fn example7() {
        assert_eq!(
            Solution::length_of_longest_substring("tmmzuxt".to_string()),
            5
        );
    }
}
