const N: usize = 100001;

fn dfs(i: usize, cnt: &Vec<i64>, dp: &mut Vec<i64>) -> i64 {
    if i >= N {
        return 0;
    }
    if dp[i] != -1 {
        return dp[i];
    }
    if cnt[i] == 0 {
        return dfs(i + 1, cnt, dp);
    }
    dp[i] = dfs(i + 1, cnt, dp).max(cnt[i] + dfs(i + 2, cnt, dp));
    dp[i]
}

fn main() {
    let n: usize = read();
    let mut cnt = vec![0i64; N];
    for _ in 0..n {
        let x: i64 = read();
        cnt[x as usize] += x;
    }
    let mut dp = vec![-1; N];
    let ans = dfs(1, &cnt, &mut dp);
    println!("{ans}");
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