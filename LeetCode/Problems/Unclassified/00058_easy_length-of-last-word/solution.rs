impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let splits: Vec<&str> = s.split_whitespace().collect();

        match splits.last() {
            None => 0,
            Some(word) => word.len() as i32,
        }
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(Solution::length_of_last_word("Hello World".to_string()), 5);
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::length_of_last_word(" ".to_string()), 0);
    }

    #[test]
    fn example3() {
        assert_eq!(
            Solution::length_of_last_word("Today is a nice day".to_string()),
            3
        );
    }
}
