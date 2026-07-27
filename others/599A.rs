fn solve() {
    let d1: i32 = read();
    let d2: i32 = read();
    let d3: i32 = read();

    let ans = (d1 + d2 + d3)
        .min(2 * (d1 + d2))
        .min(2 * (d1 + d3))
        .min(2 * (d2 + d3));
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
