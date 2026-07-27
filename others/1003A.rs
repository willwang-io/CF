fn main() {
    let n: usize = read();
    let mut cnt: Vec<i32> = vec![0; 101];
    let mut ans = 0;
    for _ in 0..n {
        let x: usize = read();
        cnt[x] += 1;
        ans = ans.max(cnt[x]);
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