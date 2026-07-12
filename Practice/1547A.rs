fn solve() {
    let xa: i32 = read();
    let ya: i32 = read();
    let xb: i32 = read();
    let yb: i32 = read();
    let xf: i32 = read();
    let yf: i32 = read();

    let mut dist = (xa - xb).abs() + (ya - yb).abs();

    if xa == xb && xb == xf && yf > ya.min(yb) && yf < ya.max(yb) {
        dist += 2;
    } else if ya == yb && yb == yf && xf > xa.min(xb) && xf < xa.max(xb) {
        dist += 2;
    }

    println!("{dist}");
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
