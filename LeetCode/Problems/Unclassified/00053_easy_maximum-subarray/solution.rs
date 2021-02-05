use std::cmp::max;

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut largest_sum = i32::min_value();
        let mut current_sum = 0;

        for num in nums {
            current_sum = max(num, current_sum + num);
            largest_sum = max(largest_sum, current_sum);
        }

        largest_sum
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(
            Solution::max_sub_array(vec![-2, 1, -3, 4, -1, 2, 1, -5, 4]),
            6
        );
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::max_sub_array(vec![1]), 1);
    }
    #[test]
    fn example3() {
        assert_eq!(Solution::max_sub_array(vec![0]), 0);
    }
    #[test]
    fn example4() {
        assert_eq!(Solution::max_sub_array(vec![-1]), -1);
    }
    #[test]
    fn example5() {
        assert_eq!(Solution::max_sub_array(vec![-100000]), -100000);
    }
}
