fn solve() {
    let s: String = read();
    let s = s.as_bytes();
    let mut cnt = [0; 26];
    for &b in s {
        cnt[(b - b'a') as usize] += 1;
    }
    let mut ans: i32 = cnt.iter().map(|&x| x.min(2)).sum();
    println!("{}", ans / 2);
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
