// Created: Aug  1 2026, 14:58:34
// Formatted with rustfmt.

fn main() {
    let n: usize = read();
    let a: Vec<Vec<u8>> = (0..n).map(|_| read::<String>().into_bytes()).collect();
    for j in 0..a[0].len() {
        let mut ok = true;
        for i in 1..n {
            if a[i][j] != a[i - 1][j] {
                ok = false;
            }
        }
        if !ok {
            println!("{j}");
            break;
        }
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
