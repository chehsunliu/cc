use std::error::Error;
use std::io;

// 2^31 - 1 = 2147483647
// 10^9 * 10^9 = 10^18 = (10^3)^6 ~= (2^10)^6 = 2^60
fn solve(heights: Vec<i32>, k: i32) -> i32 {
    0
}

fn main() -> Result<(), Box<dyn Error>> {
    let stdin = io::stdin();
    let mut buffer = String::new();

    stdin.read_line(&mut buffer)?;

    loop {
        buffer.clear();
        if stdin.read_line(&mut buffer)? == 0 {
            break;
        }

        let words: Vec<&str> = buffer.trim().split_whitespace().collect();
        let k: i32 = words[1].parse()?;

        buffer.clear();
        if stdin.read_line(&mut buffer)? == 0 {
            break;
        }

        let heights: Vec<i32> = buffer
            .trim()
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();

        println!("{}", solve(heights, k));
    }

    Ok(())
}
