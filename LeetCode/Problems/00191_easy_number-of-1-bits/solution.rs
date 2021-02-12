mod leetcode;

impl Solution {
    pub fn hammingWeight (n: u32) -> i32 {
        let mut n = n;
        let mut count = 0;

        while n > 0 {
            count += (n % 2) as i32;
            n /= 2;
        }

        count
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(Solution::hammingWeight(11), 3);
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::hammingWeight(128), 1);
    }
}
