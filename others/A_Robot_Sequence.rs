fn solve() {

}

fn main() {
    let n: usize = read();
    let s: String = read();
    let mut ans = 0;
    for i in 0..n {
        for j in i+1..=n {
            let mut x = 0;
            let mut y = 0;
            for &b in s[i..j].as_bytes() {
                match b {
                    b'U' => x -= 1,
                    b'R' => y += 1,
                    b'D' => x += 1,
                    b'L' => y -= 1,
                    _ => continue, 
                }
            }
            println!();
            if x == 0 && y == 0 {
                ans += 1;
            }
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