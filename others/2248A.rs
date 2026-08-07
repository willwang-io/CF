// Created: Aug  5 2026, 20:16:39
// Formatted with rustfmt.

fn solve() {
    let s = read::<String>().into_bytes();
    let mut ans = vec![];

    for i in 0..s.len() {
        if s[i] == b'1' {
            continue;
        }
        let mut a = s.clone();
        a.remove(i);

        let mut j = a.iter().position(|&c| c == b'1').unwrap();
        for k in 0..a.len() - 1 {
            if a[k] == b'1' && a[k + 1] == b'0' {
                j = k;
                break;
            }
        }

        a.remove(j);
        if a > ans {
            ans = a;
        }
    }
    let ans = String::from_utf8(ans).unwrap();
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
