mod leetcode;

impl Solution {
    pub fn count_primes(n: i32) -> i32 {
        if n <= 2 {
            return 0;
        }

        let mut marks = vec![true; n as usize];
        marks[0] = false;
        marks[1] = false;

        for prime in 2..n {
            if prime * prime >= n {
                break;
            }

            if marks[prime as usize] {
                for i in prime..n {
                    if prime * i >= n {
                        break;
                    }
                    marks[(prime * i) as usize] = false;
                }
            }
        }

        let mut count = 0;
        for mark in marks {
            count += if mark { 1 } else { 0 };
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
        assert_eq!(Solution::count_primes(10), 4);
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::count_primes(0), 0);
    }

    #[test]
    fn example3() {
        assert_eq!(Solution::count_primes(1), 0);
    }

    #[test]
    fn example4() {
        assert_eq!(Solution::count_primes(432), 83);
    }

    #[test]
    fn example5() {
        assert_eq!(Solution::count_primes(51541), 5275);
    }

    #[test]
    fn example6() {
        assert_eq!(Solution::count_primes(2), 0);
    }

    #[test]
    fn example7() {
        assert_eq!(Solution::count_primes(3), 1);
    }
}
