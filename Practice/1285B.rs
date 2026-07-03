fn kadane(a: &[i64]) -> i64 {
    let mut ans = a[0];
    let mut mx = a[0];
    for i in 1..a.len() {
        mx = a[i].max(mx + a[i]);
        ans = ans.max(mx);
    }
    ans
}

fn solve() {
    let n: usize = read();
    let a: Vec<i64> = (0..n).map(|_| read()).collect();
    let sum: i64 = a.iter().sum();
    let tmp = kadane(&a[..n-1]).max(kadane(&a[1..]));
    if tmp >= sum {
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