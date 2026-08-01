// Created: Aug  1 2026, 02:06:37
// Formatted with rustfmt.

fn solve() {
    let n: i32 = read();
    let m = n / 2;
    for i in 0..n {
        let ans = (0..n)
            .map(|j| {
                if (i - m).abs() + (j - m).abs() <= m {
                    'D'
                } else {
                    '*'
                }
            })
            .collect::<String>();
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
