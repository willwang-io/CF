// Created: Aug  1 2026, 15:06:19
// Formatted with rustfmt.

fn main() {
    let n: i64 = read();
    let k: i64 = read();
    let d = n / 2 / (k + 1);
    let c = d * k;
    let r = n - d - c;
    println!("{d} {c} {r}");
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
