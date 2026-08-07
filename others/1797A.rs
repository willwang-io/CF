// Created: Aug  6 2026, 14:08:30
// Formatted with rustfmt.

fn solve() {
    let n: usize = read();
    let m: usize = read();
    let x1: usize = read();
    let y1: usize = read();
    let x2: usize = read();
    let y2: usize = read();

    let f = |x: usize, y: usize| -> i32 {
        if (x == 1 || x == n) && (y == 1 || y == m) {
            2
        } else if (x == 1 || x == n) || (y == 1 || y == m) {
            3
        } else {
            4
        }
    };

    println!("{}", f(x1, y1).min(f(x2, y2)));
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
