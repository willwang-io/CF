fn solve() {
    let n: usize = read();
    let s: String = read();
    let mut cnt = [0, 0, 0, 0];
    for b in s.bytes() {
        if b == b'?' {
            continue;
        }
        cnt[(b - b'A') as usize] += 1;
    }
    let ans: usize = cnt.iter().map(|&x| x.min(n)).sum();
    println!("{ans}");
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
