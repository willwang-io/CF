fn solve() {
    let n: usize = read();
    let a: Vec<i64> = (0..n).map(|_| read()).collect();
    let b: Vec<i64> = (0..n).map(|_| read()).collect();
    const MOD: i64 = 998244353;
    let mut dp0 = 1_i64;
    let mut dp1 = 1_i64;
    for i in 0..n-1 {
        let a0 = a[i];
        let b0 = b[i];
        let a1 = b[i];
        let b1 = a[i];
        let c0 = a[i + 1];
        let d0 = b[i + 1];
        let c1 = b[i + 1];
        let d1 = a[i + 1];
        let mut na0 = 0;
        let mut na1 = 0;
        if a0 <= c0 && b0 <= d0 {
            na0 = (na0 + dp0) % MOD;
        } 
        if a0 <= c1 && b0 <= d1 {
            na1 = (na1 + dp0) % MOD;
        }
        if a1 <= c0 && b1 <= d0 {
            na0 = (na0 + dp1) % MOD;
        }
        if a1 <= c1 && b1 <= d1 {
            na1 = (na1 + dp1) % MOD;
        }
        dp0 = na0;
        dp1 = na1;
    }
    println!("{}", (dp0 + dp1) % MOD);
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