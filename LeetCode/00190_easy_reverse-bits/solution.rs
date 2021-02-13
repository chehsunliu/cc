mod leetcode;

impl Solution {
    pub fn reverse_bits(x: u32) -> u32 {
        let mut x = x;
        let mut ans = 0;

        for _ in 0..32 {
            ans *= 2;
            let r = x % 2;
            x /= 2;
            ans += r;
        }

        ans
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(Solution::reverse_bits(43261596), 964176192);
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::reverse_bits(4294967293), 3221225471);
    }
}
