fn solve() {
    let mut s: String = read();
    let b = s.as_bytes();
    for i in 1..b.len() {
        if b[i] == b[i - 1] {
            let mut c = b'a';
            while c == b[i] {
                c += 1;
            }
            s.insert(i, c as char);
            println!("{s}");
            return;
        }
    }
    let mut c = b'a';
    while c == b[0] {
        c += 1;
    }
    println!("{}{s}", c as char);
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