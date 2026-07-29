// Created: Jul 29 2026, 10:59:47
// Formatted with rustfmt.

fn solve() {
    let s: String = read();
    let mut seen = [false; 26];
    let mut cnt = 0;
    let mut ans = 1;

    for b in s.bytes() {
        let i = (b - b'a') as usize;

        if !seen[i] {
            if cnt == 3 {
                seen = [false; 26];
                cnt = 0;
                ans += 1;
            }
            seen[i] = true;
            cnt += 1;
        }
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
