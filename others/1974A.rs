fn solve() {
    let mut x: i32 = read();
    let mut y: i32 = read();
    let mut ans = 0;
    let mut empty_spaces = 0;
    while y > 0 {
        if y >= 2 {
            y -= 2;
            empty_spaces += 7;
        } else {
            y -= 1;
            empty_spaces += 11;
        }
        ans += 1;
    }
    let tmp = (0.max(x - empty_spaces) + 14) / 15;
    println!("{}", ans + tmp);
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