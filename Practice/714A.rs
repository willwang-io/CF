fn main() {
    let l1: i64 = read();
    let r1: i64 = read();
    let l2: i64 = read();
    let r2: i64 = read();
    let k: i64 = read();
    let mut ans = 0;
    let l = l1.max(l2);
    let r = r1.min(r2);
    if l <= r {
        ans = r - l + 1;
        if k >= l && k <= r {
            ans -= 1;
        }
    }
    println!("{ans}");
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