fn main() {
    let n: usize = read();
    let mut ans = 0_i64;
    let mut neg_cnt = 0;
    let mut zero_cnt = 0;
    for _ in 0..n {
        let x: i64 = read();
        if x < 0 {
            neg_cnt += 1;
            ans += -x - 1;
        } else if x == 0 {
            zero_cnt += 1;
            ans += 1;
        } else {
            ans += x - 1;
        }
    }
    if neg_cnt % 2 == 1 && zero_cnt == 0 {
        ans += 2;
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