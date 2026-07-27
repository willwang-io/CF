fn solve() {
    let n: usize = read();
    let c: i64 = read();
    let x: i64 = read();
    let mut p: i64 = read();

    let mut ans = 1;
    for i in 1..n {
        let t: i64 = read();
        if t - p > c {
            ans = 1;
        } else {
            ans += 1;
        }
        p = t;
    }
    println!("{ans}");
}

fn main() {
    solve();
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
