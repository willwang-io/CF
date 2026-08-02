// Created: Jul 29 2026, 12:07:01
// Formatted with rustfmt.

fn main() {
    let n: usize = read();
    let m: usize = read();

    let mut dp = vec![vec![i32::MAX / 2; 501]; 501];

    for a in 1..=n {
        for b in 1..=m {
            if a == b {
                dp[a][b] = 0;
                continue;
            }
            for i in 1..=a / 2 {
                dp[a][b] = dp[a][b].min(1 + dp[i][b] + dp[a - i][b]);
            }
            for j in 1..=b / 2 {
                dp[a][b] = dp[a][b].min(1 + dp[a][j] + dp[a][b - j]);
            }
        }
    }

    println!("{}", dp[n][m]);
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
