fn solve() {
    let mut a: Vec<i64> = (0..4).map(|_| read()).collect();
    let mut ans: i64 = 0;
    let mn = a[0].min(a[2]).min(a[3]);
    ans += 256 * mn;
    a[0] -= mn;
    let mn = a[0].min(a[1]);
    ans += 32 * mn;
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
