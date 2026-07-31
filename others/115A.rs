// Created: Jul 31 2026, 17:17:12
// Formatted with rustfmt.

fn depth(i: usize, p: &[i32], d: &mut [i32]) -> i32 {
    if d[i] != 0 {
        return d[i];
    }
    let x = if p[i] == -1 {
        1
    } else {
        depth(p[i] as usize - 1, p, d) + 1
    };
    d[i] = x;
    x
}

fn solve() {
    let n: usize = read();
    let p: Vec<i32> = (0..n).map(|_| read()).collect();
    let mut d = vec![0; n];
    let mut ans = 0;
    for i in 0..n {
        ans = ans.max(depth(i, &p, &mut d));
    }
    println!("{ans}");
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
