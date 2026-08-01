// Created: Jul 31 2026, 17:56:01
// Formatted with rustfmt.

fn solve() {
    let x: i32 = read();
    let y: i32 = read();
    let z: i32 = read();
    let t1: i32 = read();
    let t2: i32 = read();
    let t3: i32 = read();
    let stairs = (x - y).abs() * t1;
    let elevator = ((z - x).abs() + (x - y).abs()) * t2 + 3 * t3;
    if elevator <= stairs {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn main() {
    solve();
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
