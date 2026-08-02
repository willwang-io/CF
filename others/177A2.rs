// Created: Aug  1 2026, 14:49:31
// Formatted with rustfmt.

fn main() {
    let n: usize = read();
    let mut ans = 0;
    for i in 0..n {
        for j in 0..n {
            let x: i32 = read();
            if i == j || i + j == n - 1 || i == n / 2 || j == n / 2 {
                ans += x;
            }
        }
    }
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
