// Created: Aug  1 2026, 20:26:56
// Formatted with rustfmt.

fn solve() {
    let n: i32 = read();
    let mut m: i32 = read();
    m %= n * (n + 1) / 2;
    for i in 1..=n {
        if m < i {
            break;
        }
        m -= i;
    }
    println!("{m}");
}

fn main() {
    solve();
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
