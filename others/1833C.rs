// Created: Jul 31 2026, 15:37:44
// Formatted with rustfmt.

fn solve() {
    let n: usize = read();
    let mut mn = i32::MAX;
    let mut odd = false;
    for _ in 0..n {
        let x: i32 = read();
        mn = mn.min(x);
        odd |= x % 2 == 1;
    }
    if mn % 2 == 1 || !odd {
        println!("YES");
    } else {
        println!("NO");
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
