// Created: Jul 29 2026, 11:35:24
// Formatted with rustfmt.

fn main() {
    let n: usize = read();
    let m: usize = read();
    let a: Vec<i32> = (0..n).map(|_| read()).collect();
    let b: Vec<i32> = (0..m).map(|_| read()).collect();

    let mut dp = vec![vec![0; m + 1]; n + 1];

    for i in 1..=n {
        for j in 1..=m {
            dp[i][j] = dp[i - 1][j].max(dp[i][j - 1]);
            if a[i - 1] == b[j - 1] {
                dp[i][j] = dp[i][j].max(1 + dp[i - 1][j - 1]);
            }
        }
    }

    let mut i = n;
    let mut j = m;
    let mut seq = vec![];

    while i > 0 && j > 0 {
        if a[i - 1] == b[j - 1] {
            seq.push(a[i - 1]);
            i -= 1;
            j -= 1;
        } else if dp[i - 1][j] >= dp[i][j - 1] {
            i -= 1;
        } else {
            j -= 1;
        }
    }

    seq.reverse();
    println!("{}", dp[n][m]);

    let ans = seq
        .iter()
        .map(|&x| x.to_string())
        .collect::<Vec<_>>()
        .join(" ");
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
