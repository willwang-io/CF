fn solve() {
    let n: usize = read();
    let a: Vec<i32> = (0..n).map(|_| read()).collect();

    let sum: i32 = a.windows(2).map(|w| (w[0] - w[1]).abs()).sum();
    let mut mx = (a[0] - a[1]).abs().max((a[n - 2] - a[n - 1]).abs());
    for w in a.windows(3) {
        mx = mx.max((w[0] - w[1]).abs() + (w[1] - w[2]).abs() - (w[0] - w[2]).abs());
    }

    println!("{}", sum - mx);
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
