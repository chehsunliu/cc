impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        if strs.is_empty() {
            return "".to_string();
        }

        let mut ans = String::new();
        let min_length = strs
            .iter()
            .map(|s| s.len())
            .fold(usize::max_value(), |l1, l2| if l1 > l2 { l2 } else { l1 });

        for index in 0..min_length {
            let c = strs[0].chars().nth(index).unwrap();

            for s in strs.iter() {
                if c != s.chars().nth(index).unwrap() {
                    return String::from(&strs[0][0..index]);
                }
            }
        }

        String::from(&strs[0][0..min_length])
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(
            Solution::longest_common_prefix(vec![
                "flower".to_string(),
                "flow".to_string(),
                "flight".to_string()
            ]),
            "fl".to_string()
        );
    }

    #[test]
    fn example2() {
        assert_eq!(
            Solution::longest_common_prefix(vec![
                "dog".to_string(),
                "racecar".to_string(),
                "car".to_string()
            ]),
            "".to_string()
        );
    }
}
