// Created: Aug  1 2026, 15:08:59
// Formatted with rustfmt.

fn solve() {
    let s: String = read();
    let p = s.find('.').unwrap();
    let a = &s[..p];
    if a.ends_with('9') {
        println!("GOTO Vasilisa.");
    } else if s.as_bytes()[p + 1] >= b'5' {
        let mut ans = a.as_bytes().to_vec();
        *ans.last_mut().unwrap() += 1;
        let ans = String::from_utf8(ans).unwrap();
        println!("{ans}");
    } else {
        println!("{a}");
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
