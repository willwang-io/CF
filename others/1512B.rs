fn solve() {
    let n: usize = read();
    let mut g: Vec<Vec<char>> = (0..n).map(|_| read::<String>().chars().collect()).collect();

    let mut x = (n, n);
    let mut y = (n, n);
    for i in 0..n {
        for j in 0..n {
            if g[i][j] == '*' {
                if x.0 == n {
                    x = (i, j);
                } else {
                    y = (i, j);
                }
            }
        }
    }

    if x.0 == y.0 {
        let r = if x.0 == 0 { 1 } else { 0 };
        g[r][x.1] = '*';
        g[r][y.1] = '*';
    } else if x.1 == y.1 {
        let c = if x.1 == 0 { 1 } else { 0 };
        g[x.0][c] = '*';
        g[y.0][c] = '*';
    } else {
        g[x.0][y.1] = '*';
        g[y.0][x.1] = '*';
    }

    for row in g {
        println!("{}", row.into_iter().collect::<String>());
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
