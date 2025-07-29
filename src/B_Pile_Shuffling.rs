//  B. Pile Shuffling

use std::io::Read;

fn solve(sc: &mut Scanner) -> () {
    let n: usize = sc.next();
    let (mut x, mut y, mut z) = (0i64, 0i64, 0i64);
    for _ in 0..n {
        let a: i64 = sc.next();
        let b: i64 = sc.next();
        let c: i64 = sc.next();
        let d: i64 = sc.next();
        if a > c {
            x += a - c;
        }
        if b > d {
            y += b - d;
            z += a.min(c);
        }
    }
    println!("{}", x + y + z);
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