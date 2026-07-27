fn solve() {
    let n: usize = read();
    let mut k: i32 = read();
    let mut a: Vec<i32> = (0..n).map(|_| read()).collect();
    let mut b: Vec<i32> = (0..n).map(|_| read()).collect();
    let mut zip: Vec<(i32, i32)> = a
        .into_iter()
        .zip(b.into_iter())
        .collect();
    zip.sort();
    for (a, b) in zip {
        if a <= k {
            k += b;
        } 
    }
    println!("{k}");
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