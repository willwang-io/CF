fn gcd(mut a: i64, mut b: i64) -> i64 {
    while b > 0 {
        (a, b) = (b, a % b);
    }
    a
}

fn solve() {
    let n: usize = read();
    let mut a: Vec<i64> = (0..n).map(|_| read()).collect();
    a.sort();
    let mut g = a[0];
    for i in 0..n {
        g = gcd(g, a[i]);
        if g > (i + 1) as i64 {
            println!("NO");
            return;
        }
    }
    println!("YES");
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
