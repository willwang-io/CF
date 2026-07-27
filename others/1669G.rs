// Created: Jul 26 2026, 22:16:53
// Formatted with rustfmt.

fn solve() {
    let n: usize = read();
    let m: usize = read();
    let mut a: Vec<Vec<char>> = (0..n).map(|_| read::<String>().chars().collect()).collect();

    for i in (0..n - 1).rev() {
        for j in 0..m {
            if a[i][j] != '*' {
                continue;
            }
            let mut ci = i;
            while ci + 1 < n && a[ci + 1][j] == '.' {
                ci += 1;
            }
            (a[i][j], a[ci][j]) = (a[ci][j], a[i][j]);
        }
    }

    let ans = a
        .into_iter()
        .map(|row| row.into_iter().collect::<String>())
        .collect::<Vec<_>>()
        .join("\n");
    println!("\n{ans}");
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
