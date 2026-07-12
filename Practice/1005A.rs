fn main() {
    let n: usize = read();
    let a: Vec<i32> = (0..n).map(|_| read()).collect();
    let mut prev = 0;
    let mut ans = vec![];
    for i in 0..n {
        if a[i] <= prev {
            ans.push(prev);
        }
        prev = a[i];
    }
    ans.push(prev);
    println!("{}", ans.len());
    for x in ans {
        print!("{} ", x);
    }
    println!("");
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
