// Created: Jul 25 2026, 21:23:07

fn main() {
    let _: usize = read();
    let s: Vec<u8> = read::<String>().into_bytes();
    let mut ans = 0;

    for (i, b) in s.into_iter().enumerate() {
        if (b - b'0') % 2 == 0 {
            ans += i + 1;
        }
    }

    println!("{ans}");
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
