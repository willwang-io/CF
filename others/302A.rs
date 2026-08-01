// Created: Jul 31 2026, 17:53:22
// Formatted with rustfmt.

fn solve() {
    let n: usize = read();
    let m: usize = read();
    let pos = (0..n).filter(|_| read::<i32>() == 1).count();
    let limit = 2 * pos.min(n - pos);
    for _ in 0..m {
        let l: usize = read();
        let r: usize = read();
        let len = r - l + 1;
        let ans = if len % 2 == 0 && len <= limit { 1 } else { 0 };
        println!("{ans}");
    }
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
