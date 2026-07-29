// Created: Jul 27 2026, 12:51:08
// Formatted with rustfmt.

fn solve() {
    let n: usize = read();
    let m: i64 = read();
    let mut a: Vec<i64> = (0..n).map(|_| read()).collect();
    a.sort_unstable_by(|x, y| y.cmp(x));

    let mut ans = 0;
    for i in 0..n.min(m as usize) {
        ans += a[i] * (m - i as i64);
    }
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
