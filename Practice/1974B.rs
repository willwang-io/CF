use std::collections::HashMap;

fn solve() {
    let n: usize = read();
    let s: String = read();

    let mut t: Vec<u8> = s.bytes().collect();
    t.sort();
    t.dedup();

    let m = t.len();
    let mut cnt: HashMap<u8, u8> = HashMap::new();

    for i in 0..(m + 1) / 2 {
        cnt.insert(t[i], t[m - i - 1]);
        cnt.insert(t[m - i - 1], t[i]);
    }

    let tmp: String = s.bytes().map(|b| *cnt.get(&b).unwrap() as char).collect();
    println!("{tmp}");
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
