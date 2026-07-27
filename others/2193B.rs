fn solve() {
    let n: usize = read();
    let mut a: Vec<i32> = (0..n).map(|_| read()).collect();
    let mut mx = 0;
    let mut pos = n - 1;

    let mut suf = vec![0; n];
    for i in (0..n).rev() {
        if a[i] > mx {
            mx = a[i];
            pos = i;
        }
        suf[i] = pos;
    }
    for i in 0..n {
        if a[suf[i]] > a[i] {
            a[i..=suf[i]].reverse();
            break;
        }
    }
    for i in 0..n {
        print!("{} ", a[i]);
    }
    println!("");
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
