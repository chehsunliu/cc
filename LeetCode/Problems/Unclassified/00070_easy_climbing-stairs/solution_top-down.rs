use std::collections::HashMap;

impl Solution {
    fn climb(n: i32, history: &mut HashMap<i32, i32>) -> i32 {
        if let Some(x) = history.get(&n) {
            return *x;
        }

        let result = Solution::climb(n - 1, history) + Solution::climb(n - 2, history);
        history.insert(n, result);
        return result;
    }

    pub fn climb_stairs(n: i32) -> i32 {
        let mut history = HashMap::new();
        history.insert(1, 1);
        history.insert(2, 2);

        return Solution::climb(n, &mut history);
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
        assert_eq!(Solution::climb_stairs(28), 21);
    }
}
