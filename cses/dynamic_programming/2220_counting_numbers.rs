// Created: Jul 29 2026, 22:35:49
// Formatted with rustfmt.

fn dfs(pos: usize, prev: u8, tight: bool, digits: &[u8]) -> i64 {
    if pos >= digits.len() {
        return 0;
    }
    let mut ans = 0;
    if pos == 0 {
        for i in 1..10 {
            ans += 1 + dfs(pos + 1, i, i >= digits[pos], digits);
        }
    } else {
        let limit = if tight { digits[pos] } else { 9 };
        for i in 0..=limit {
            if i == prev {
                continue;
            }
            ans += 1 + dfs(pos + 1, i, tight && i == digits[pos], digits);
        }
    }
    ans
}

fn main() {
    let a: Vec<u8> = (read::<i64>() - 1)
        .to_string()
        .bytes()
        .map(|b| b - b'0')
        .collect();
    let b: Vec<u8> = read::<String>().bytes().map(|b| b - b'0').collect();

    let ans = dfs(0, 0, true, &b) - dfs(0, 0, true, &a);
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
