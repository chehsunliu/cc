use std::collections::HashMap;

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack: Vec<char> = Vec::new();
        let mut pairs = HashMap::new();
        pairs.insert(')', '(');
        pairs.insert(']', '[');
        pairs.insert('}', '{');

        for c in s.chars() {
            match c {
                ')' | ']' | '}' => match stack.pop() {
                    Some(popped_c) => {
                        if popped_c != *pairs.get(&c).unwrap() {
                            return false;
                        }
                    }
                    None => {
                        return false;
                    }
                },
                _ => stack.push(c),
            }
        }

        stack.is_empty()
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(Solution::is_valid("()".to_string()), true);
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::is_valid("()[]{}".to_string()), true);
    }

    #[test]
    fn example3() {
        assert_eq!(Solution::is_valid("(]".to_string()), false);
    }

    #[test]
    fn example4() {
        assert_eq!(Solution::is_valid("([)]".to_string()), false);
    }

    #[test]
    fn example5() {
        assert_eq!(Solution::is_valid("{[]}".to_string()), true);
    }

    #[test]
    fn example6() {
        assert_eq!(Solution::is_valid("{".to_string()), false);
        assert_eq!(Solution::is_valid(")".to_string()), false);
    }
}
