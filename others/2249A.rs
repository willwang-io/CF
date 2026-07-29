// Created: Jul 26 2026, 14:35:49

fn solve() {
    let n: usize = read();
    let mut a = Vec::with_capacity(n);
    for _ in 0..n {
        a.push((
            read::<usize>(),
            read::<usize>(),
            read::<usize>(),
            read::<usize>(),
        ));
    }

    let mut ans = 0;
    for m in (1..=n).rev() {
        let mut j = 1;
        for &(l, r, u, v) in &a {
            let k = m - j + 1;
            if (j < l || j > r) && (k < u || k > v) {
                j += 1;
                if j > m {
                    break;
                }
            }
        }
        if j > m {
            ans = m;
            break;
        }
    }
    println!("{ans}");
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
