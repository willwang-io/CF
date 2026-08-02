// Created: Jul 30 2026, 00:31:30
// Formatted with rustfmt.

fn solve() {
    let n: usize = read();
    let mut a: Vec<i32> = (0..n).map(|_| read()).collect();
    let m: usize = read();

    for _ in 0..m {
        let x = read::<usize>() - 1;
        let y: i32 = read();
        let right = a[x] - y;

        if x > 0 {
            a[x - 1] += y - 1;
        }

        if x + 1 < n {
            a[x + 1] += right;
        }

        a[x] = 0;
    }

    for ans in a {
        println!("{ans}");
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
