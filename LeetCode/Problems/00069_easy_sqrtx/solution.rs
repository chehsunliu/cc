impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        if x < 4 {
            return if x == 0 { 0 } else { 1 };
        }

        let x: u64 = x as u64;
        let mut l: u64 = 1;
        let mut r: u64 = x;

        while l <= r {
            let m = (l + r) / 2;
            let value = m * m;

            if value == x {
                return m as i32;
            } else if value > x {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        l as i32 - 1
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(Solution::my_sqrt(4), 2);
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::my_sqrt(8), 2);
    }

    #[test]
    fn example3() {
        assert_eq!(Solution::my_sqrt(2147395599), 2);
    }
}
