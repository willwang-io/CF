fn main() {
    let n: usize = read();
    let s: String = read();
    let mut ans = i32::MAX;
    let dist = |x: u8, y: u8| -> i32 {
        let mut x = x as i32;
        let mut y = y as i32;
        if x > y {
            (x, y) = (y, x);
        }
        (y - x).min((x - y + 26) % 26)
    };
    for i in 0..=n-4 {
        let cur = &s[i..i+4].as_bytes();
        ans = ans.min(dist(cur[0], b'A') + dist(cur[1], b'C') + dist(cur[2], b'T') + dist(cur[3], b'G'));
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