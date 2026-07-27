fn solve() {
    let n: usize = read();
    let mut has_one = false;
    let mut sum = 0;
    for _ in 0..n {
        let x: i64 = read();
        sum += x;
        has_one |= x % 3 == 1;
    }
    if sum % 3 == 0 {
        println!("{}", 0);
    } else if (sum % 3 == 2 || has_one) {
        println!("{}", 1);
    } else {
        println!("{}", 2);
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