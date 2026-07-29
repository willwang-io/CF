// Created: Jul 29 2026, 00:07:56
// Formatted with rustfmt.

fn main() {
    let n: usize = read();
    let x: usize = read();
    let h: Vec<usize> = (0..n).map(|_| read()).collect();
    let s: Vec<usize> = (0..n).map(|_| read()).collect();

    let mut dp = vec![0; x + 1];

    for i in 0..n {
        for j in (h[i]..=x).rev() {
            dp[j] = dp[j].max(dp[j - h[i]] + s[i]);
        }
    }

    println!("{}", dp[x]);
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
