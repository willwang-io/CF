//  A. Vanya and Cubes

use std::io::Read;

fn solve(sc: &mut Scanner) -> () {
    let n: i32 = sc.next();
    let mut cur = 0;
    for i in 1..500 {
        let tmp = i * (i + 1) / 2;
        if cur + tmp > n {
            println!("{}", i - 1);
            break;
        }
        cur += tmp;
    }
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