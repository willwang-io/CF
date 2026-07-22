fn solve() {
    let n: usize = read();
    let d: i32 = read();
    let a: Vec<i32> = (0..n).map(|_| read()).collect();
    let mut ans = 0;
    for i in 0..n {
        for j in 0..n {
            if i != j && (a[i] - a[j]).abs() <= d {
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
