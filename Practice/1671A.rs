// Created: Jul 25 2026, 23:14:49

fn solve() {
    let s: Vec<u8> = read::<String>().into_bytes();
    let mut cnt = 1;
    let mut prev = s[0];
    for &b in &s[1..] {
        if b != prev {
            if cnt == 1 {
                println!("NO");
                return;
            }
            cnt = 1;
        } else {
            cnt += 1;
        }
        prev = b;
    }
    if cnt != 1 {
        println!("YES");
    } else {
        println!("NO");
    }
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
