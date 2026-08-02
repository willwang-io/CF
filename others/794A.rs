// Created: Aug  1 2026, 15:03:52
// Formatted with rustfmt.

fn main() {
    let _: i32 = read();
    let b: i32 = read();
    let c: i32 = read();
    let n: usize = read();
    let ans = (0..n)
        .filter(|_| {
            let x: i32 = read();
            b < x && x < c
        })
        .count();
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
