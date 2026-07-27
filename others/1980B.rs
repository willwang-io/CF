fn solve() {
    let n: usize = read();
    let f: usize = read();
    let k: usize = read();
    let a: Vec<i32> = (0..n).map(|_| read()).collect();

    let greater = a.iter().filter(|&&x| x > a[f - 1]).count();
    let equal = a.iter().filter(|&&x| x == a[f - 1]).count();

    if greater >= k {
        println!("NO");
    } else if greater + equal <= k {
        println!("YES");
    } else {
        println!("MAYBE");
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
