// Created: Jul 25 2026, 21:43:20

fn main() {
    let n: usize = read();
    let s: Vec<u8> = read::<String>().into_bytes();
    let mut cnt = 0;
    for (i, b) in s.into_iter().enumerate() {
        if b != b'4' && b != b'7' {
            println!("NO");
            return;
        }
        if i >= n / 2 {
            cnt += if b == b'4' { 1 } else { -1 };
        } else {
            cnt += if b == b'4' { -1 } else { 1 };
        }
    }
    if cnt == 0 {
        println!("YES");
    } else {
        println!("NO");
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
