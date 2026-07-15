fn gcd(mut a: i64, mut b: i64) -> i64 {
    while b > 0 {
        (a, b) = (b, a % b);
    }
    a
}

fn solve() {
    let n: i64 = read();
    let x: i64 = read();
    let y: i64 = read();

    let g = gcd(x, y);
    let mut ok = true;

    for i in 1..=n {
        let p: i64 = read();
        if i % g != p % g {
            ok = false;
        }
    }

    if ok {
        println!("YES");
    } else {
        println!("NO");
    }
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
