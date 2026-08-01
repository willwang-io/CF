// Created: Jul 31 2026, 17:59:01
// Formatted with rustfmt.

fn solve() {
    let _: i32 = read();
    let m: i32 = read();
    let k: i32 = read();
    let p = k - 1;
    let r = p / (2 * m) + 1;
    let d = p % (2 * m) / 2 + 1;
    let s = if p % 2 == 0 { 'L' } else { 'R' };
    println!("{r} {d} {s}");
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
