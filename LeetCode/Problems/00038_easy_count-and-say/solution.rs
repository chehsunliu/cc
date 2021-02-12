impl Solution {
    pub fn count_and_say(n: i32) -> String {
        let mut ans = String::from("1");

        for _ in 1..n {
            let mut count = 1;
            let mut pre_c = ans.chars().nth(0).unwrap();
            let mut tmp_ans = String::new();

            for (i, c) in ans.as_str().chars().enumerate() {
                if i == 0 {
                    continue;
                }

                if pre_c == c {
                    count += 1;
                } else {
                    let number = pre_c as u8 - '0' as u8;
                    tmp_ans.push_str(count.to_string().as_str());
                    tmp_ans.push_str(number.to_string().as_str());
                    pre_c = c;
                    count = 1;
                }
            }

            let number = pre_c as u8 - '0' as u8;
            tmp_ans.push_str(count.to_string().as_str());
            tmp_ans.push_str(number.to_string().as_str());

            ans = tmp_ans;
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
        assert_eq!(Solution::count_and_say(1), "1".to_string());
    }

    #[test]
    fn example2() {
        assert_eq!(Solution::count_and_say(4), "1211".to_string());
    }
}
