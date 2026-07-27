fn solve() {
    let n: usize = read();
    let c: i32 = read();
    let mut a: Vec<i32> = (0..n).map(|_| read()).collect();
    let mut b: Vec<i32> = (0..n).map(|_| read()).collect();
    let mut ans = i32::MAX;
    let mut cur: i32 = 0;
    let mut ok: bool = true;
    for i in 0..n {
        if a[i] < b[i] {
            ok = false;
        }
        cur += a[i] - b[i];
    }
    if ok {
        ans = ans.min(cur);
    }
    a.sort();
    b.sort();
    cur = c;
    ok = true;
    for i in 0..n {
        if a[i] < b[i] {
            ok = false;
        }
        cur += a[i] - b[i];
    }
    if ok {
        ans = ans.min(cur);
    }
    if ans == i32::MAX {
        println!("-1");
    } else {
        println!("{ans}");
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