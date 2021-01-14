impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut pos = 0;

        for i in 0..nums.len() {
            if nums[i] != val {
                nums.swap(i, pos);
                pos += 1;
            }
        }

        pos as i32
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        let mut nums = vec![3, 2, 2, 3];
        assert_eq!(Solution::remove_element(&mut nums, 3), 2);
        assert_eq!(&nums[0..2], vec![2, 2].as_slice());
    }

    #[test]
    fn example2() {
        let mut nums = vec![0, 1, 2, 2, 3, 0, 4, 2];
        assert_eq!(Solution::remove_element(&mut nums, 2), 5);
        assert_eq!(&nums[0..5], vec![0, 1, 4, 0, 3].as_slice());
    }
}
