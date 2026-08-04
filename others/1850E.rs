// Created: Aug  3 2026, 15:28:18
// Formatted with rustfmt.

fn solve() {
    let n: usize = read();
    let c: i64 = read();
    let A: Vec<i64> = (0..n).map(|_| read()).collect();

    let ok = |x: i64| -> bool {
        let mut total = 0i128;
        for &a in &A {
            let v = a as i128 + 2 * x as i128;
            total += v * v;
            if total > c as i128 {
                return false;
            }
        }
        true
    };

    let mut left = 1;
    let mut right = 1e19 as i64;

    while left < right {
        let mid = left + (right - left + 1) / 2;
        if ok(mid) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    println!("{left}");
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
