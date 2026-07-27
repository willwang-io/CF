fn solve() {
    let s: String = read();
    let s: Vec<usize> = s.bytes().map(|b| (b - b'0') as usize).collect();
    let mut cnt = [0; 10];
    for x in s {
        cnt[x] += 1;
    }
    for i in 0..10 {
        for d in 9 - i..10 {
            if cnt[d] > 0 {
                print!("{d}");
                cnt[d] -= 1;
                break;
            }
        }
    }
    println!("");
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
