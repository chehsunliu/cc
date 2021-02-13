impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        if needle.is_empty() {
            return 0;
        }

        if needle.len() > haystack.len() {
            return -1;
        }

        for start_pos in 0..(haystack.len() - needle.len() + 1) {
            if &haystack[start_pos..start_pos + needle.len()] == &needle[..] {
                return start_pos as i32;
            }
        }

        -1
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(Solution::str_str("hello".to_string(), "ll".to_string()), 2);
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::str_str("aaaaa".to_string(), "bba".to_string()), -1);
    }

    #[test]
    fn example3() {
        assert_eq!(Solution::str_str("".to_string(), "".to_string()), 0);
    }

    #[test]
    fn example4() {
        assert_eq!(Solution::str_str("a".to_string(), "a".to_string()), 0);
    }
}
