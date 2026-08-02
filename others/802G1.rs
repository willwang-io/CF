// Created: Aug  1 2026, 14:54:51
// Formatted with rustfmt.

fn main() {
    let s: String = read();
    let t = "heidi".as_bytes();
    let mut i = 0;

    for b in s.bytes() {
        if i < t.len() && b == t[i] {
            i += 1;
        }
    }
    if i == t.len() {
        println!("YES");
    } else {
        println!("NO");
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
