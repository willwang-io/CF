// Created: Jul 31 2026, 17:20:07
// Formatted with rustfmt.

fn main() {
    let mut cnt = [0; 26];
    for _ in 0..2 {
        let s: String = read();
        for c in s.bytes() {
            cnt[(c - b'A') as usize] += 1;
        }
    }
    let s: String = read();
    for c in s.bytes() {
        cnt[(c - b'A') as usize] -= 1;
    }
    if cnt.iter().all(|&x| x == 0) {
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
