//  A. Only One Digit

use std::io::Read;

fn solve(sc: &mut Scanner) {
    let mut x: i32 = sc.next();
    let mut ans = 10;
    while x != 0 {
        ans = ans.min(x % 10);
        x /= 10;
    }
    println!("{}", ans);
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