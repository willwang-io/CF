// Created: Aug  5 2026, 11:18:22
// Formatted with rustfmt.

fn main() {
    let s: String = read();
    let cnt = s.chars().filter(|&c| c == 'a').count();
    let n = s.len();
    if 2 * cnt > n {
        println!("{n}");
    } else {
        println!("{}", cnt * 2 - 1);
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
