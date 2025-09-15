fn solve() {
    let n: usize = read();
    let mut a = vec![0; n + 1];
    for i in 1..=n {
        let x: i32 = read();
        a[i] = x;
    }
    let mut pre = vec![0; n + 1];
    for i in 1..=n {
        pre[i] = pre[i - 1] + a[i];
    }
    for l in 1..=n-2 {
        for r in l+1..=n-1 {
            let s1 = pre[l] % 3;
            let s2 = (pre[r] - pre[l]) % 3;
            let s3 = (pre[n] - pre[r]) % 3;
            if (s1 == s2 && s2 == s3) || (s1 != s2 && s1 != s3 && s2 != s3) {
                println!("{} {}", l, r);
                return;
            }
        }
    }
    println!("0 0");
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