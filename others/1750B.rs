// Created: Aug  6 2026, 18:06:08
// Formatted with rustfmt.

fn solve() {
    let n: usize = read();
    let s: Vec<char> = read::<String>().chars().collect();
    let mut one = s.iter().filter(|&&c| c == '1').count();
    let mut zero = n - one;
    let mut ans = one * zero;

    let mut z = 0;
    let mut o = 0;
    for c in s {
        if c == '0' {
            ans = ans.max(o * o);
            o = 0;
            z += 1;
        } else {
            ans = ans.max(z * z);
            z = 0;
            o += 1;
        }
    }
    println!("{}", ans.max(z * z).max(o * o));
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
