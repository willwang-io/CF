// Created: Jul 29 2026, 11:17:38
// Formatted with rustfmt.

fn solve() {
    let n: usize = read();
    let mut sum = 0_i64;
    let mut mx = i64::MIN;

    for _ in 0..n {
        let x: i64 = read();
        sum += x;
        mx = mx.max(x);
    }

    let ans = mx as f64 + (sum - mx) as f64 / (n - 1) as f64;
    println!("{ans:.9}");
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
