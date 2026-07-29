// Created: Jul 26 2026, 21:56:39
// Formatted with rustfmt.

fn main() {
    let n: usize = read();
    let mut a = 0;
    let mut b = 0;
    for _ in 0..n {
        if read::<i32>() == 1 {
            a += 1;
        } else {
            b += 1;
        }
    }

    let x = a.min(b);
    let ans = x + (a - x) / 3;
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
