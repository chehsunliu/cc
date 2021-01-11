use std::io;
use std::process;
use std::cmp::min;

// 10^9 * 10^9 = 10^18 = (10^3)^6 ~= (2^10)^6 = 2^60

fn solve(mut vec_a: Vec<i32>, mut vec_b: Vec<i32>) -> i32 {
    let mut votes_a: i32 = vec_a.iter().sum();
    let mut votes_b: i32 = vec_b.iter().sum();

    if votes_a > votes_b {
        return 0;
    }

    vec_a.sort();
    vec_b.sort();
    vec_b.reverse();

    let index_bound = min(vec_a.len(), vec_b.len());
    for index in 0..index_bound {
        votes_a += vec_b[index] - vec_a[index];
        votes_b += vec_a[index] - vec_b[index];
        if votes_a > votes_b {
            return index as i32 + 1
        }
    }

    -1
}

fn main() {
    let stdin = io::stdin();
    let mut buffer = String::new();

    stdin
        .read_line(&mut buffer)
        .expect("Failed to read # of cases");

    loop {
        let mut buffer = String::new();
        match stdin.read_line(&mut buffer) {
            Ok(0) => break,
            Ok(_) => {}
            Err(_) => process::exit(1),
        }

        let mut buffer = String::new();
        match stdin.read_line(&mut buffer) {
            Ok(0) => break,
            Ok(_) => {}
            Err(_) => process::exit(1),
        }

        let vec_a: Vec<i32> = buffer
            .trim()
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();

        let mut buffer = String::new();
        match stdin.read_line(&mut buffer) {
            Ok(0) => break,
            Ok(_) => {}
            Err(_) => process::exit(1),
        }

        let vec_b: Vec<i32> = buffer
            .trim()
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();

        println!("{}", solve(vec_a, vec_b));
    }
}
