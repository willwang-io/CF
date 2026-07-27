#![allow(unused_imports)]
use std::cmp::{min, max, Reverse};
use std::collections::{
    VecDeque, BinaryHeap,
    HashMap, HashSet,
    BTreeMap, BTreeSet
};


fn solve() {
    let n: usize = read();

    let mut psum: Vec<i32> = vec![0; n + 1];
    for i in 0..n {
        let x: i32 = read();
        psum[i + 1] = psum[i] + if x == 1 { 1 } else { -1 };
    }

    let ok = |k: usize| -> bool {
        psum.windows(2 * k + 1).any(|w| w[2 * k] - w[0] == 0 && (w[k] - w[0]).abs() == k as i32)
    };

    let mut lo = 0;
    let mut hi = n / 2;
    while lo < hi {
        let mid = lo + (hi - lo + 1) / 2;
        if ok(mid) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    println!("{}", lo * 2);
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