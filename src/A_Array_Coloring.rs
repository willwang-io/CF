use std::io::Read;

fn solve(sc: &mut Scanner) -> () {
    let n = sc.next();
    let mut cnt = 0;
    for _ in 0..n {
        let x: i32 = sc.next();
        if x % 2 == 1 {
            cnt += 1;
        }
    }
    if cnt % 2 == 1 {
        println!("NO");
    } else {
        println!("YES");
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