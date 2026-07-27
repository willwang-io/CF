fn solve() {
    let n: usize = read();
    let m: usize = read();
    let a: Vec<Vec<char>> = (0..n).map(|_| read::<String>().chars().collect()).collect();

    let mut x1 = 200;
    let mut y1 = 200;
    let mut x2 = 0;
    let mut y2 = 0;

    for i in 0..n {
        for j in 0..m {
            if a[i][j] == 'B' {
                x1 = x1.min(i);
                y1 = y1.min(j);
                x2 = x2.max(i);
                y2 = y2.max(j);
            }
        }
    }

    println!("{} {}", (x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1);
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
