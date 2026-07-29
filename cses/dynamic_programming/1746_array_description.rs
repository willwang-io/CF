// Created: Jul 28 2026, 22:23:28
// Formatted with rustfmt.

const MOD: i64 = 1e9 as i64 + 7;

fn main() {
    let n: usize = read();
    let m: usize = read();
    let a: Vec<usize> = (0..n).map(|_| read()).collect();

    let mut dp = vec![0i64; m + 2];

    if a[0] == 0 {
        dp[1..=m].fill(1);
    } else {
        dp[a[0]] = 1;
    }

    for i in 1..n {
        let mut ndp = vec![0i64; m + 2];
        for j in if a[i] == 0 { 1..=m } else { a[i]..=a[i] } {
            ndp[j] = (dp[j - 1] + dp[j] + dp[j + 1]) % MOD;
        }
        dp = ndp;
    }

    let ans = dp[1..=m].iter().sum::<i64>() % MOD;
    println!("{ans}");
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
