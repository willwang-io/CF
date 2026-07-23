use std::collections::HashMap;

fn solve() {
    let s: String = read();
    let t: String = read();
    let a: String = read();

    let tmp: HashMap<char, char> = s.chars().zip(t.chars()).collect();

    for c in a.chars() {
        let lower = c.to_ascii_lowercase();
        match tmp.get(&lower) {
            Some(&x) => {
                if c.is_ascii_uppercase() {
                    print!("{}", x.to_ascii_uppercase());
                } else {
                    print!("{x}");
                }
            }
            None => {
                print!("{c}");
            }
        }
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
