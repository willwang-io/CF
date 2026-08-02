// Created: Aug  2 2026, 01:34:11
// Formatted with rustfmt.

fn main() {
    let n: i32 = read();
    let mut p = 0;
    let mut ans = vec![];
    for i in 1..n {
        p = (p + i) % n;
        ans.push((p + 1).to_string());
    }
    let ans = ans.join(" ");
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
