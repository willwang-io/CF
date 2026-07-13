fn solve() {
    let s: String = read();
    for i in 1..s.len() {
        let a = &s[..i];
        let b = &s[i..];
        if b.starts_with('0') {
            continue;
        }
        let a: i32 = a.parse().unwrap();
        let b: i32 = b.parse().unwrap();
        if b > a {
            println!("{a} {b}");
            return;
        }
    }
    println!("-1");
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
