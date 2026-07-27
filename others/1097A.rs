fn main() {
    let s: String = read();
    let s = s.as_bytes();
    let a: Vec<String> = (0..5).map(|_| read()).collect();
    let ok = a.iter().any(|x| {
        let t = x.as_bytes();
        t[0] == s[0] || t[1] == s[1]
    });
    println!("{}", if ok { "YES" } else { "NO" });
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