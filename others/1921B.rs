fn solve() {
    let n: usize = read();
    let s: String = read();
    let f: String = read();

    let s = s.as_bytes();
    let f = f.as_bytes();

    let mut x = 0;
    let mut y = 0;
    for i in 0..n {
        if s[i] == b'1' && f[i] == b'0' {
            x += 1;
        } else if s[i] == b'0' && f[i] == b'1' {
            y += 1;
        }
    }
    println!("{}", x.max(y));
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
