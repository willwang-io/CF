fn solve() {
    let n: usize = read();
    let s: String = read();
    let mut cnt = [0; 26];
    for b in s.bytes() {
        cnt[(b - b'a') as usize] += 1;
    }
    let zero = cnt[25];
    let one = cnt[4] - zero;
    for _ in 0..one {
        print!("1 ");
    }
    for _ in 0..zero {
        print!("0 ");
    }
    println!("");
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
