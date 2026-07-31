// Created: Jul 31 2026, 17:03:59
// Formatted with rustfmt.

fn solve() {
    let n: usize = read();
    let m: usize = read();
    let g: Vec<Vec<u8>> = (0..n).map(|_| read::<String>().into_bytes()).collect();
    let mut x1 = 100;
    let mut y1 = 100;
    let mut x2 = 0;
    let mut y2 = 0;

    for i in 0..n {
        for j in 0..m {
            if g[i][j] == b'*' {
                x1 = x1.min(i);
                y1 = y1.min(j);
                x2 = x2.max(i);
                y2 = y2.max(j);
            }
        }
    }

    for i in x1..=x2 {
        for j in y1..=y2 {
            print!("{}", g[i][j] as char);
        }
        println!();
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

