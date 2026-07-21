fn solve() {
    let n: usize = read();
    let h: i32 = read();
    let l: i32 = read();

    let mut r = 0;
    let mut c = 0;
    let mut u = 0;

    for _ in 0..n {
        let x: i32 = read();
        if x <= h {
            r += 1;
        }
        if x <= l {
            c += 1;
        }
        if x <= h.max(l) {
            u += 1;
        }
    }
    println!("{}", r.min(c).min(u / 2));
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
