// Created: Jul 28 2026, 22:15:02
// Formatted with rustfmt.

const MOD: i64 = 1e9 as i64 + 7;

fn main() {
    let n: usize = read();
    let mut dp = vec![0_i64; n + 1];
    dp[0] = 1;

    for i in 0..=n {
        for j in 1..=6 {
            if i >= j {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }
    println!("{}", dp[n]);
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
