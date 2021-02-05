mod list_node;

impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        for i in (0..(m as usize)).rev() {
            nums1[i + n as usize] = nums1[i];
        }

        let mut index1: usize = n as usize;
        let mut index2: usize = 0;
        for i in 0..((m + n) as usize) {
            if index2 as i32 >= n || (index1 as i32 - n < m && nums1[index1] < nums2[index2]) {
                nums1[i] = nums1[index1];
                index1 += 1;
            } else {
                nums1[i] = nums2[index2];
                index2 += 1;
            }
        }
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        let mut nums1 = vec![1, 2, 3, 0, 0, 0];
        let mut nums2 = vec![2, 5, 6];
        Solution::merge(&mut nums1, 3, &mut nums2, 3);
        assert_eq!(nums1, vec![1, 2, 2, 3, 5, 6]);
    }

    #[test]
    fn example2() {
        let mut nums1 = vec![1];
        let mut nums2 = vec![];
        Solution::merge(&mut nums1, 1, &mut nums2, 0);
        assert_eq!(nums1, vec![1]);
    }

    #[test]
    fn example3() {
        let mut nums1 = vec![1, 2, 3, 0, 0];
        let mut nums2 = vec![1, 2];
        Solution::merge(&mut nums1, 3, &mut nums2, 2);
        assert_eq!(nums1, vec![1, 1, 2, 2, 3]);
    }
}
