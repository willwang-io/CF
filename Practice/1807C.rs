fn solve() {
    let n: usize = read();
    let s: String = read();
    let mut a = [-1; 26];
    let mut prev = 0;
    for b in s.bytes() {
        let i = (b - b'a') as usize;
        if a[i] != -1 && a[i] != prev {
            println!("NO");
            return;
        }
        a[i] = prev;
        prev ^= 1;
    }
    println!("YES");
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
