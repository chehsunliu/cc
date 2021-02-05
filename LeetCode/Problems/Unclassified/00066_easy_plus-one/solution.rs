impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut ans = vec![];
        let mut carry = 1;

        for i in (0..digits.len()).rev() {
            let current = digits[i] + carry;
            ans.push(current % 10);
            carry = current / 10;
        }

        if carry > 0 {
            ans.push(carry);
        }

        ans.reverse();
        ans
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(Solution::plus_one(vec![1, 2, 3]), vec![1, 2, 4]);
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::plus_one(vec![4, 3, 2, 1]), vec![4, 3, 2, 2]);
    }

    #[test]
    fn example3() {
        assert_eq!(Solution::plus_one(vec![0]), vec![1]);
    }
}
