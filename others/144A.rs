// Created: Aug  3 2026, 15:05:22
// Formatted with rustfmt.

fn main() {
    let n: usize = read();
    let mut max = 0;
    let mut min = 101;
    let mut l = 0;
    let mut r = 0;
    for i in 0..n {
        let x: i32 = read();
        if x > max {
            max = x;
            l = i;
        }
        if x <= min {
            min = x;
            r = i;
        }
    }
    let ans = l + n - r - 1 - usize::from(l > r);
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
