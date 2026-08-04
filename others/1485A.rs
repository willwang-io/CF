// Created: Aug  3 2026, 18:43:59
// Formatted with rustfmt.

fn solve() {
    let a: i32 = read();
    let b: i32 = read();
    let mut ans = i32::MAX;
    for add in 0..=32 {
        let d = b + add;
        if d == 1 {
            continue;
        }
        let mut x = a;
        let mut ops = add;
        while x > 0 {
            x /= d;
            ops += 1;
        }
        ans = ans.min(ops);
    }
    println!("{ans}");
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
