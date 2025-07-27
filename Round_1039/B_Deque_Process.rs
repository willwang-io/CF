//  B. Deque Process

use std::collections::VecDeque;
use std::io::Read;

fn solve(sc: &mut Scanner) -> () {
    let n: usize = sc.next();
    let mut p: VecDeque<usize> = (0..n).map(|_| sc.next()).collect();
    let mut ans = String::new();
    let mut prev = true;
    while !p.is_empty() {
        if p.len() == 1 {
            ans.push_str("L");
            break;
        }
        let front = p.pop_front().unwrap();
        let back = p.pop_back().unwrap();
        if prev == (front < back) {
            ans.push_str("LR");
        } else {
            ans.push_str("RL");
        }
        prev = !prev;
    }
    println!("{ans}");
}

fn main() {
    let mut sc = Scanner::new();
    let t: usize = sc.next();
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