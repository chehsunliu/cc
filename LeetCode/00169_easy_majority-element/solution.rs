use std::collections::HashMap;

mod leetcode;

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut history = HashMap::new();
        let mut majority = nums[0];
        history.insert(majority, 1);

        for i in 1..nums.len() {
            let count = 1 + match history.get(&nums[i]) {
                None => 0,
                Some(count) => *count,
            };

            history.insert(nums[i], count);
            if count > *history.get(&majority).unwrap() {
                majority = nums[i];
            }
        }

        majority
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(Solution::majority_element(vec![3, 2, 3]), 3);
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::majority_element(vec![2, 2, 1, 1, 1, 2, 2]), 2);
    }
}
