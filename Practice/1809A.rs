// Created: Jul 25 2026, 17:23:03

fn solve() {
    let s: String = read();
    let mut cnt = [0; 10];
    for b in s.bytes() {
        cnt[(b - b'0') as usize] += 1;
    }
    match cnt.into_iter().max().unwrap() {
        4 => println!("-1"),
        3 => println!("6"),
        _ => println!("4"),
    }
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
