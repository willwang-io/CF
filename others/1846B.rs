// Created: Jul 30 2026, 00:23:25
// Formatted with rustfmt.

fn solve() {
    let a: Vec<Vec<u8>> = (0..3).map(|_| read::<String>().into_bytes()).collect();
    let mut winner = b'.';

    for i in 0..3 {
        if a[i][0] != b'.' && a[i][0] == a[i][1] && a[i][1] == a[i][2] {
            winner = a[i][0];
        }

        if a[0][i] != b'.' && a[0][i] == a[1][i] && a[1][i] == a[2][i] {
            winner = a[0][i];
        }
    }

    if a[0][0] != b'.' && a[0][0] == a[1][1] && a[1][1] == a[2][2] {
        winner = a[0][0];
    }

    if a[0][2] != b'.' && a[0][2] == a[1][1] && a[1][1] == a[2][0] {
        winner = a[0][2];
    }

    let ans = match winner {
        b'X' => "X",
        b'O' => "O",
        b'+' => "+",
        _ => "DRAW",
    };

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
