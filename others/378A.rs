// Created: Aug  1 2026, 02:32:35
// Formatted with rustfmt.

fn main() {
    let a: i8 = read();
    let b: i8 = read();
    let mut cnt = [0, 0, 0];
    for x in 1..7 {
        let p = (a - x).abs();
        let q = (b - x).abs();
        if p == q {
            cnt[1] += 1;
        } else if p > q {
            cnt[2] += 1;
        } else {
            cnt[0] += 1;
        }
    }
    println!("{} {} {}", cnt[0], cnt[1], cnt[2]);
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
