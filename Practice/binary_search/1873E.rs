fn solve() {
    let n: usize = read();
    let x: i64 = read();
    let a: Vec<i64> = (0..n).map(|_| read()).collect();
    let mut lo = 1;
    let mut hi = 1e10 as i64;
    while lo < hi {
        let mid = lo + (hi - lo + 1) / 2;
        let total: i64 = a.iter().map(|&x| 0.max(mid - x)).sum();
        if total <= x {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    println!("{}", lo);
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