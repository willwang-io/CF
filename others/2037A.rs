// Created: Aug  3 2026, 22:44:23
// Formatted with rustfmt.

fn solve() {
    let n: usize = read();
    let mut cnt = vec![0; 21];
    for _ in 0..n {
        let x: usize = read();
        cnt[x] += 1;
    }
    let ans = cnt.iter().map(|&x| x / 2).sum::<i32>();
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
