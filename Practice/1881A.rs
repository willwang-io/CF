fn solve() {
    let _n: usize = read();
    let _m: usize = read();
    let mut x: String = read();
    let s: String = read();
    for ans in 0..=10 {
        if x.contains(&s) {
            println!("{ans}");
            return;
        }
        let doubled = x.clone();
        x.push_str(&doubled);
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
