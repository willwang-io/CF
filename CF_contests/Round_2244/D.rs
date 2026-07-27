fn solve() {
    let n: usize = read();
    let m: usize = read();

    let mut psum: Vec<i64> = vec![0; n + 1];
    for i in 1..=n {
        let x: i64 = read();
        psum[i] = x + psum[i - 1];
    }

    let mut b: Vec<usize> = (0..m).map(|_| read()).collect();
    b.sort();

    let mut ans = 0;
    let mut prev = 0;
    for x in b {
        ans += (psum[x] - psum[prev]).abs();
        prev = x;
    }

    ans += psum[n] - psum[prev];
    println!("{}", ans);
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
