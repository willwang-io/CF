// Created: Aug  7 2026, 17:45:13
// Formatted with rustfmt.

fn solve() {
    let n: i64 = read();
    let a: i64 = read();
    let b: i64 = read();
    let k = 0.max((b - a).min(n));

    let mut ans = a * (n - k);
    ans += b * (b + 1) / 2;
    ans -= (b - k) * (b - k + 1) / 2;
    println!("{ans}");
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
