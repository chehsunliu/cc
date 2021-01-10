use std::io;
use std::process;

// 2^31 - 1 = 2147483647
fn solve(a: u64, b: u64) -> u64 {
    let a_odds = (a + 1) / 2;
    let a_evens = a / 2;
    let b_odds = (b + 1) / 2;
    let b_evens = b / 2;

    // 10^9 * 10^9 = 10^18 = (10^3)^6 ~= (2^10)^6 = 2^60
    a_odds * b_odds + a_evens * b_evens
}

fn main() {
    let stdin = io::stdin();
    let mut buffer = String::new();

    stdin
        .read_line(&mut buffer)
        .expect("Failed to read # of cases");

    loop {
        buffer.clear();
        let stdin_result = stdin.read_line(&mut buffer);

        if let Err(_) = stdin_result {
            process::exit(1);
        } else if let Ok(0) = stdin_result {
            break;
        }

        let words: Vec<&str> = buffer.trim().split_whitespace().collect();
        let a: u64 = words[0].parse().unwrap();
        let b: u64 = words[1].parse().unwrap();

        println!("{}", solve(a, b));
    }
}
