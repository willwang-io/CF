fn solve() {
    let n: usize = read();
    let mut a = vec![];
    for i in 0..n {
        let mut sum = 0;
        for _ in 0..4 {
            let x: i32 = read();
            sum += x;
        }
        a.push((-sum, i));
    }
    a.sort();
    for i in 0..n {
        if a[i].1 == 0 {
            print!("{}", i + 1);
        }
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
