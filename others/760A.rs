// Created: Aug  1 2026, 14:47:53
// Formatted with rustfmt.

fn main() {
    let m: usize = read();
    let d: i32 = read();
    let days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let ans = (days[m - 1] + d + 5) / 7;
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
