impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 || (x % 10 == 0 && x != 0) {
            return false;
        }

        let mut x = x;
        let mut reversed = 0;
        while x > reversed {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        // 1221 0 -> 122 1
        // 122 1 -> 12 12

        // 4112 0 -> 411 2
        // 411 2 -> 41 21
        // 41 21 -> 4 211

        // 121 0 -> 12 1
        // 12 1 -> 1 12

        x == reversed || x == reversed / 10
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert!(Solution::is_palindrome(121));
    }

    #[test]
    fn example2() {
        assert!(!Solution::is_palindrome(-121));
    }

    #[test]
    fn example3() {
        assert!(!Solution::is_palindrome(10));
    }

    #[test]
    fn example4() {
        assert!(!Solution::is_palindrome(-101));
    }

    #[test]
    fn example5() {
        assert!(Solution::is_palindrome(312213));
    }

    #[test]
    fn example6() {
        assert!(!Solution::is_palindrome(313213));
    }

    #[test]
    fn example7() {
        assert!(Solution::is_palindrome(12321));
    }

    #[test]
    fn example8() {
        assert!(!Solution::is_palindrome(1123311));
    }
}
