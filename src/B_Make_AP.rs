//  B. Make AP

use std::io::Read;

fn solve(sc: &mut Scanner) -> () {
    let a: i32 = sc.next();
    let b: i32 = sc.next();
    let c: i32 = sc.next();

    let ok = (2 * b - c > 0 && (2 * b - c) % a == 0) ||
        ((a + c) % (2 * b) == 0) ||
        (2 * b - a > 0 && (2 * b - a) % c == 0);
    if ok {
        println!("YES");
    } else {
        println!("NO");
    }
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