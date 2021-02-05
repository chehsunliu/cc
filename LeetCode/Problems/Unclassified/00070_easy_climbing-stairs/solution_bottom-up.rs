impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n <= 2 {
            return n;
        }

        let mut n0 = 1;
        let mut n1 = 2;

        for i in 0..(n - 2) {
            let tmp = n0 + n1;
            n0 = n1;
            n1 = tmp;
        }

        n1
    }
}

enum Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        assert_eq!(Solution::climb_stairs(2), 2);
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::climb_stairs(3), 3);
    }

    #[test]
    fn example3() {
        assert_eq!(Solution::climb_stairs(7), 21);
    }

    #[test]
    fn example4() {
        assert_eq!(Solution::climb_stairs(45), 1836311903);
    }
}