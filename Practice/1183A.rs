fn solve() {
    let n: i32 = read();
    for i in 0..10 {
        let sum: i32 = (n + i).to_string().bytes().map(|x| (x - b'0') as i32).sum();
        if sum % 4 == 0 {
            println!("{}", n + i);
            return;
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
