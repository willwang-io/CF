fn solve() {
    let a: i64 = read();
    let b: i64 = read();

    fn get(mut a: i64, mut b: i64) -> i32 {
        let mut ans: i64 = 0;
        let mut x: i64 = 1;
        loop {
            if ans % 2 == 0 {
                if a < x {
                    break;
                }
                a -= x;
            } else {
                if b < x {
                    break;
                }
                b -= x;
            }
            ans += 1;
            x *= 2;
        }
        ans as _
    }
    println!("{}", get(a, b).max(get(b, a)));
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