fn solve() {
    let n: usize = read();
    let a: Vec<Vec<i32>> = (0..n)
        .map(|_| (0..n).map(|_| read::<i32>()).collect())
        .collect();
    for i in 0..n {
        for j in 0..n {
            if a[i][j] == 1 {
                continue;
            }
            let mut ok = false;
            for x in 0..n {
                for y in 0..n {
                    if a[i][x] + a[y][j] == a[i][j] {
                        ok = true;
                    }
                }
            }
            if !ok {
                println!("No");
                return;
            }
        }
    }
    println!("Yes");
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
