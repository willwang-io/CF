fn solve() {
    let n: usize = read();
    let k: usize = read();
    let mut set = std::collections::BTreeSet::new();
    let mut cnt = 0;
    for _ in 0..n {
        let x: usize = read();
        if x == k {
            cnt += 1;
        } else if x < k {
            set.insert(x);
        }
    }
    if set.len() == k {
        println!("{cnt}");
    } else {
        let need = k - set.len();
        if cnt >= need {
            println!("{cnt}");
        } else {
            println!("{need}");
        }
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
