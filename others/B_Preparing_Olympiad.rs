fn main() {
    let n: usize = read();
    let l: usize = read();
    let r: usize = read();
    let x: usize = read();
    let a: Vec<usize> = (0..n).map(|_| read()).collect();
    let mut ans = 0;
    for i in 0..1 << n {
        let mut cnt = 0;
        let mut mx = usize::MIN;
        let mut mn = usize::MAX;
        let mut total = 0;
        for j in 0..n {
            if i & (1 << j) != 0 {
                cnt += 1;
                mx = mx.max(a[j]);
                mn = mn.min(a[j]);
                total += a[j];
            }
        }
        if cnt >= 2 && total >= l && total <= r && mx - mn >= x {
            ans += 1;
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