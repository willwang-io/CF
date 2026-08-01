// Created: Jul 31 2026, 17:43:14
// Formatted with rustfmt.

fn solve() {
    let n: usize = read();
    let s: String = read();
    let s = s.as_bytes();
    let mut i = 0;
    let mut press = 0;
    let mut ok = true;
    while i < n {
        if press % 2 == 0 {
            i += 1;
        } else if i + 1 < n && s[i] == s[i + 1] {
            i += 2;
        } else {
            ok = false;
            break;
        }
        press += 1;
    }

    if ok {
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
