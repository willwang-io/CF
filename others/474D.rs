const MOD: i64 = 1_000_000_007;

fn main() {
    let t: usize = read();
    let k: usize = read();

    let mut dp: Vec<i64> = vec![0; 100001]; 
    let mut psum: Vec<i64> = vec![0; 100001];

    dp[0] = 1;
    psum[0] = 1;

    for i in 1..=100000 {
        dp[i] += dp[i - 1];
        if i >= k {
            dp[i] = (dp[i] + dp[i - k]) % MOD;
        }
        psum[i] = (psum[i - 1] + dp[i]) % MOD;
    }

    for _ in 0..t {
        let a: usize = read();
        let b: usize = read();
        println!("{}", (psum[b] - psum[a - 1] + MOD) % MOD);
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