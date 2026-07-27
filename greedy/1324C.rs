// Created: Jul 27 2026, 00:10:23
// Formatted with rustfmt.

fn solve() {
    let s: Vec<_> = read::<String>().chars().collect();
    let mut prev = 0;
    let mut ans = 0;
    for i in 0..s.len() {
        if s[i] == 'R' {
            let p = i + 1;
            ans = ans.max(p - prev);
            prev = p;
        }
    }
    println!("{}", ans.max(s.len() + 1 - prev));
}

fn main() {
    let t: usize = read();
    for _ in 0..t {
        solve();
    }
}

thread_local! {
    pub static INPUT: std::cell::RefCell<std::str::SplitAsciiWhitespace<'static>> = std::cell::RefCell::<std::str::SplitAsciiWhitespace<'static>>::new({
        let mut input = String::new();
        std::io::Read::read_to_string(&mut std::io::stdin(), &mut input).unwrap();
        Box::leak(input.into_boxed_str()).split_ascii_whitespace()
    });
}

pub fn read<T: std::str::FromStr>() -> T
where
    T::Err: std::fmt::Debug,
{
    INPUT.with(|input| input.borrow_mut().next().unwrap().parse().unwrap())
}
