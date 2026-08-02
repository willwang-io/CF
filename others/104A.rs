// Created: Aug  1 2026, 20:29:09
// Formatted with rustfmt.

fn main() {
    let n: i32 = read();
    let x = n - 10;
    let ans = if x == 10 {
        15
    } else if x == 1 || x == 11 || 2 <= x && x <= 9 {
        4
    } else {
        0
    };
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
