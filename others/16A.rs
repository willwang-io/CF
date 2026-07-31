// Created: Jul 31 2026, 17:09:45
// Formatted with rustfmt.

fn solve() {
    let n: usize = read();
    let _: usize = read();
    let mut prev = b'?';
    let mut ok = true;
    for _ in 0..n {
        let s: String = read();
        let s = s.as_bytes();
        ok &= s.iter().all(|&c| c == s[0]) && s[0] != prev;
        prev = s[0];
    }
    if ok {
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

