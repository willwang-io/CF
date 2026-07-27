fn solve() {
    let n: usize = read();
    let m: usize = read();
    let g: Vec<Vec<char>> = (0..n).map(|_| read::<String>().chars().collect()).collect();

    let mut ans = 0;
    for j in 0..m - 1 {
        if g[n - 1][j] != 'R' {
            ans += 1;
        }
    }
    for i in 0..n - 1 {
        if g[i][m - 1] != 'D' {
            ans += 1;
        }
    }

    println!("{ans}");
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
