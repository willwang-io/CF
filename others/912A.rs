fn solve() {
    let a: i64 = read();
    let b: i64 = read();
    let x: i64 = read();
    let y: i64 = read();
    let z: i64 = read();

    let p = 2 * x + y;
    let q = y + 3 * z;

    print!("{}", 0.max(p - a) + 0.max(q - b));
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
