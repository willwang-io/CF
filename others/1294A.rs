fn solve() {
    let a: i64 = read();
    let b: i64 = read();
    let c: i64 = read();
    let n: i64 = read();
    let mx = a.max(b).max(c);
    let tmp = n - (3 * mx - a - b - c);
    println!("{}", if tmp >= 0 && tmp % 3 == 0 { "YES" } else { "NO" });
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