fn solve() {
    let n: usize = read();
    let g: Vec<Vec<i32>> = (0..n).map(|_| (0..n).map(|_| read()).collect()).collect();

    let mut ans = 0;
    for i in 0..n {
        ans += g[i][i] + g[i][n - i - 1] + g[n / 2][i] + g[i][n / 2];
    }
    ans -= g[n / 2][n / 2] * 3;

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
