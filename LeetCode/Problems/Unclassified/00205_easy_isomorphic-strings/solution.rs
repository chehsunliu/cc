mod leetcode;

use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut map = HashMap::new();
        let mut mapped_values = HashSet::new();

        for i in 0..s.len() {
            let char_s = s.chars().nth(i).unwrap();
            let char_t = t.chars().nth(i).unwrap();

            if map.contains_key(&char_s) {
                if *map.get(&char_s).unwrap() != char_t {
                    return false;
                }
            } else {
                if mapped_values.contains(&char_t) {
                    return false;
                }
                map.insert(char_s, char_t);
                mapped_values.insert(char_t);
            }
        }

        true
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert!(Solution::is_isomorphic(
            "egg".to_string(),
            "add".to_string()
        ));
    }

    #[test]
    fn example2() {
        assert!(!Solution::is_isomorphic(
            "foo".to_string(),
            "bar".to_string()
        ));
    }

    #[test]
    fn example3() {
        assert!(Solution::is_isomorphic(
            "paper".to_string(),
            "title".to_string()
        ));
    }

    #[test]
    fn example4() {
        assert!(!Solution::is_isomorphic(
            "badc".to_string(),
            "baba".to_string()
        ));
    }
}
