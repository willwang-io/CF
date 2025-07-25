//  A. Panoramix's Prediction

use std::io::Read;

fn solve(sc: &mut Scanner) -> () {
    let n: i32 = sc.next();
    let m: i32 = sc.next();
    let primes = vec![2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59];
    for i in 0..primes.len() - 1 {
        if primes[i] == n && primes[i + 1] == m {
            println!("YES");
            return
        }
    }
    println!("NO");
}

fn main() {
    let mut sc = Scanner::new();
    let t = 1;
    for _ in 0..t {
        solve(&mut sc);
    }
}

struct Scanner {
    iter: std::str::SplitWhitespace<'static>,
}

impl Scanner {
    fn new() -> Self {
        let mut tmp = String::new();
        std::io::stdin().read_to_string(&mut tmp).unwrap();
        let s: &'static str = Box::leak(tmp.into_boxed_str());
        Scanner {
            iter: s.split_whitespace(),
        }
    }

    fn next<T: std::str::FromStr>(&mut self) -> T {
        self.iter.next().unwrap().parse().ok().expect("parse error")
    }
}