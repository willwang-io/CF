fn solve() {
    let n: usize = read();
    let w: Vec<i32> = (0..n).map(|_| read()).collect();

    let mut i = 0;
    let mut j = n;

    let mut a = 0;
    let mut b = 0;
    let mut ans = 0;

    while i < j {
        if a <= b {
            a += w[i];
            i += 1;
        } else {
            j -= 1;
            b += w[j];
        }
        if a == b {
            ans = ans.max(i + n - j);
        }
    }
    println!("{}", ans);
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