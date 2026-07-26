// Created: Jul 26 2026, 11:50:23

fn dfs(x: usize, y: usize, g: &mut [Vec<u8>]) {
    if g[x][y] == b'#' {
        return;
    }

    g[x][y] = b'#';

    if x >= 1 {
        dfs(x - 1, y, g);
    }

    if y >= 1 {
        dfs(x, y - 1, g);
    }

    if x + 1 < g.len() {
        dfs(x + 1, y, g);
    }

    if y + 1 < g[0].len() {
        dfs(x, y + 1, g);
    }
}

fn solve() {
    let n: usize = read();
    let m: usize = read();

    let mut g: Vec<Vec<u8>> = (0..n).map(|_| read::<String>().bytes().collect()).collect();
    let mut ans = 0;

    for x in 0..n {
        for y in 0..m {
            if g[x][y] == b'.' {
                dfs(x, y, &mut g);
                ans += 1;
            }
        }
    }

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
