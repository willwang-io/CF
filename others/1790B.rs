// Created: Jul 30 2026, 00:19:45
// Formatted with rustfmt.

fn solve() {
    let n: usize = read();
    let s: i32 = read();
    let r: i32 = read();
    let mut a = vec![r / (n - 1) as i32; n - 1];

    for i in 0..(r % (n - 1) as i32) as usize {
        a[i] += 1;
    }

    a.push(s - r);

    let ans = a
        .iter()
        .map(|x| x.to_string())
        .collect::<Vec<_>>()
        .join(" ");
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
