// Created: Aug  3 2026, 15:17:11
// Formatted with rustfmt.

fn main() {
    let n: usize = read();
    let k: i32 = read();
    let mut a: Vec<i32> = (0..n).map(|_| read()).collect();
    a.sort_unstable();
    let mut ans = 0;
    for i in (2..n).step_by(3) {
        if a[i] + k > 5 {
            break;
        }
        ans += 1;
    }
    println!("{ans}");
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
