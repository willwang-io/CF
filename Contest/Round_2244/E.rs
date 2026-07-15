fn solve() {
    let n: usize = read();
    let q: usize = read();
    let s: String = read();
    let s = s.as_bytes();

    let mut psum = vec![0_i64; n + 1];
    for i in 1..n {
        psum[i + 1] = psum[i];
        if s[i] == s[i - 1] {
            psum[i + 1] += 1;
        }
    }

    for _ in 0..q {
        let l: usize = read();
        let r: usize = read();
        let k: i64 = read();
        let x = psum[r] - psum[l];
        if (x + 1) / 2 <= k {
            println!("YES");
        } else {
            println!("NO");
        }
    }
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
