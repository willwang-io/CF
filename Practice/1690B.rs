fn solve() {
    let n: usize = read();
    let a: Vec<i32> = (0..n).map(|_| read()).collect();
    let b: Vec<i32> = (0..n).map(|_| read()).collect();
    let diff: Vec<i32> = a.iter().zip(b.iter()).map(|(&x, &y)| x - y).collect();
    if diff.iter().any(|&x| x < 0) {
        println!("NO");
        return;
    }
    let mx = diff.iter().max().unwrap();
    if a.iter().zip(b.iter()).any(|(&x, &y)| y > 0 && x - y != *mx) {
        println!("NO");
    } else {
        println!("YES");
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
