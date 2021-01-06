use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut history: HashMap<i32, i32> = HashMap::new();

        for (idx, num) in nums.iter().enumerate() {
            let complement = target - num;

            if let Some(complement_idx) = history.get(&complement) {
                return vec![*complement_idx, idx as i32];
            }

            history.insert(*num, idx as i32);
        }

        nums
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(Solution::two_sum(vec![2, 7, 11, 15], 9), vec![0, 1]);
        assert_eq!(Solution::two_sum(vec![3, 2, 4], 6), vec![1, 2]);
        assert_eq!(Solution::two_sum(vec![3, 3], 6), vec![0, 1]);
    }
}
