// Created: Jul 31 2026, 17:00:33
// Formatted with rustfmt.

fn solve() {
    let g: Vec<Vec<u8>> = (0..3).map(|_| read::<String>().into_bytes()).collect();
    if g[0][0] == g[2][2] && g[0][1] == g[2][1] && g[0][2] == g[2][0] && g[1][0] == g[1][2] {
        println!("YES");
    } else {
        println!("NO");
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

