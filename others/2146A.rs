use std::collections::HashMap;

fn solve() {
    let n: usize = read();
    let mut cnt: HashMap<i32, i32> = HashMap::new();
    for _ in 0..n {
        let x: i32 = read();
        *cnt.entry(x).or_default() += 1;
    }
    let mut vals: Vec<i32> = cnt.values().copied().collect();
    vals.sort();
    let mut ans = 0;
    for (i, &x) in vals.iter().enumerate() {
        ans = ans.max(x * (vals.len() - i) as i32);
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