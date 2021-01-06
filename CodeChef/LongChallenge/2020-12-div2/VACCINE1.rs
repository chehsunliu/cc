use std::process;
use std::io;

struct Company {
    day: i32,
    vaccines_per_day: i32,
}

fn solve(mut companies: [Company; 2], mut goals: i32) -> i32 {
    companies.sort_by(|a, b| a.day.cmp(&b.day));

    let mut answers = companies[0].day - 1;

    if companies[0].day < companies[1].day {
        let extra_days = companies[1].day - companies[0].day;

        if goals <= extra_days * companies[0].vaccines_per_day {
            return answers + goals / companies[0].vaccines_per_day +
                if goals % companies[0].vaccines_per_day > 0 { 1 } else { 0 };
        }

        goals -= extra_days * companies[0].vaccines_per_day;
        answers += extra_days;
    }

    let vaccines_per_day = companies[0].vaccines_per_day + companies[1].vaccines_per_day;

    answers + (goals / vaccines_per_day) + if goals % vaccines_per_day > 0 { 1 } else { 0 }
}

fn main() {
    let stdin = io::stdin();

    loop {
        let mut buffer = String::new();
        let stdin_result = stdin.read_line(&mut buffer);

        if let Err(_) = stdin_result {
            process::exit(1);
        }

        if let Ok(0) = stdin_result {
            break;
        }

        let split_words = buffer.trim().split_whitespace();
        let words: Vec<&str> = split_words.collect();

        let companies = [
            Company {
                day: words[0].parse().unwrap(),
                vaccines_per_day: words[1].parse().unwrap(),
            },
            Company {
                day: words[2].parse().unwrap(),
                vaccines_per_day: words[3].parse().unwrap(),
            }
        ];

        println!("{}", solve(companies, words[4].parse().unwrap()));
    }
}
