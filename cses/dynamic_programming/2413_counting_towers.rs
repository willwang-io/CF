// Created: Jul 29 2026, 00:23:54
// Formatted with rustfmt.

const MOD: i64 = 1e9 as i64 + 7;

fn main() {
    let mut dp = vec![0i64; 1_000_001];
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 8;
    for i in 3..=1_000_000 {
        dp[i] = (6 * dp[i - 1] - 7 * dp[i - 2]).rem_euclid(MOD);
    }
    let n: usize = read();
    for _ in 0..n {
        let x: usize = read();
        println!("{}", dp[x]);
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
