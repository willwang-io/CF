use std::collections::HashSet;

fn solve() {
    let n: usize = read();
    let k: usize = read();
    let mut cnt: HashSet<i32> = HashSet::new();
    let mut ans = vec![];
    for i in 0..n {
        let x: i32 = read();
        if ans.len() < k && cnt.insert(x) {
            ans.push(i);
        }
    }

    if cnt.len() == k {
        println!("YES");
        for v in ans {
            print!("{} ", v + 1);
        }
    } else {
        println!("NO");
    }
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
