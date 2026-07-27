fn solve() {
    let a: i32 = read();
    let b: i32 = read();
    let c: i32 = read();
    let x: i32 = read();
    let y: i32 = read();

    let dog = 0.max(x - a);
    let cat = 0.max(y - b);
    let mut ok = dog + cat <= c;
    println!("{}", if ok { "YES" } else { "NO" });
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