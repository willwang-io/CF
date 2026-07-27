// Created: Jul 25 2026, 21:11:47

fn solve() {
    let a: Vec<u8> = read::<String>().into_bytes();
    let mut ans = 0;
    let mut prev = b'#';

    if a.len() == 1 && a[0] == b'^' {
        println!("1");
        return;
    }

    for b in a {
        if b == b'_' {
            if prev != b'^' {
                ans += 1;
            }
        }
        prev = b;
    }
    if prev == b'_' {
        ans += 1;
    }
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
