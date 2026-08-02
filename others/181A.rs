// Created: Aug  1 2026, 20:17:04
// Formatted with rustfmt.

fn main() {
    let n: usize = read();
    let m: usize = read();
    let a: Vec<Vec<u8>> = (0..n).map(|_| read::<String>().into_bytes()).collect();
    let mut x1 = usize::MAX;
    let mut y1 = usize::MAX;
    let mut x2 = usize::MIN;
    let mut y2 = usize::MIN;
    for i in 0..n {
        for j in 0..m {
            if a[i][j] == b'*' {
                x1 = x1.min(i);
                y1 = y1.min(j);
                x2 = x2.max(i);
                y2 = y2.max(j);
            }
        }
    }
    let ans = if a[x1][y1] != b'*' {
        (x1, y1)
    } else if a[x1][y2] != b'*' {
        (x1, y2)
    } else if a[x2][y1] != b'*' {
        (x2, y1)
    } else {
        (x2, y2)
    };
    println!("{} {}", ans.0 + 1, ans.1 + 1);
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
