fn solve() {
    let mut w: usize = read();
    let mut h: usize = read();
    let n: i64 = read();
    let mut cnt: i64 = 1;
    while w > 0 && w % 2 == 0 {
        w /= 2;
        cnt *= 2;
    }
    let mut cnt2: i64 = 1;
    while h > 0 && h % 2 == 0 {
        h /= 2;
        cnt2 *= 2;
    }
    println!("{}", if cnt * cnt2 >= n { "YES" } else { "NO" });
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