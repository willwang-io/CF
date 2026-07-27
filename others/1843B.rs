fn solve() {
    let n: usize = read();
    let mut a = vec![];
    for _ in 0..n {
        let x: i64 = read();
        if x == 0 {
            continue;
        } else {
            a.push(x);
        }
    }
    let sum: i64 = a.iter().map(|&x| x.abs()).sum();
    let mut i = 0;
    let mut cnt = 0;
    while i < a.len() {
        if a[i] < 0 {
            cnt += 1;
            while i < a.len() && a[i] < 0 {
                i += 1;
            }
        } else {
            i += 1;
        }
    }
    println!("{sum} {cnt}");
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
