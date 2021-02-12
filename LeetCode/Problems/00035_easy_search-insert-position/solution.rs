impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut l: i32 = 0;
        let mut r: i32 = nums.len() as i32 - 1;

        while l <= r {
            let m = (l + r) / 2;

            if nums[m as usize] < target {
                l = m + 1;
            } else if nums[m as usize] > target {
                r = m - 1;
            } else {
                return m as i32;
            }
        }

        l
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn examples() {
        assert_eq!(Solution::search_insert(vec![1, 3, 5, 6], 5), 2);
        assert_eq!(Solution::search_insert(vec![1, 3, 5, 6], 2), 1);
        assert_eq!(Solution::search_insert(vec![1, 3, 5, 6], 7), 4);
        assert_eq!(Solution::search_insert(vec![1, 3, 5, 6], 0), 0);
        assert_eq!(Solution::search_insert(vec![1], 0), 0);
    }
}
