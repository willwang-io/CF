fn solve() {
    let n: usize = read();

    let mut seated = vec![false; n + 2];
    let mut ok = true;
    for i in 0..n {
        let x: usize = read();
        if i > 0 && !seated[x - 1] && !seated[x + 1] {
            ok = false;
        }
        seated[x] = true;
    }
    println!("{}", if ok { "YES" } else { "NO" });
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