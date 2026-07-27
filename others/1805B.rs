// Created: Jul 25 2026, 17:28:25

fn solve() {
    let _: usize = read();
    let s: Vec<u8> = read::<String>().into_bytes();
    let c = *s.iter().min().unwrap();
    let i = s.iter().rposition(|&x| x == c).unwrap();
    let mut ans = String::with_capacity(s.len());
    ans.push(c as char);
    for (j, &x) in s.iter().enumerate() {
        if i != j {
            ans.push(x as char);
        }
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
