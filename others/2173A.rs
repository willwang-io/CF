fn solve() {
    let n: usize = read();
    let k: i32 = read();
    let s: String = read();
    let s = s.as_bytes();

    let mut tmp = 0;
    let mut ans = 0;
    for &b in s {
        if b == b'1' {
            tmp = k;
        } else {
            if tmp == 0 {
                ans += 1;
            }
            tmp = 0.max(tmp - 1);
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
