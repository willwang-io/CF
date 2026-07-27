fn solve() {
    let n: usize = read();
    let mut seen = vec![true; 10];
    for _ in 0..n {
        let x: usize = read();
        seen[x] = false;
    }

    let ok = |mut x: i32| -> bool {
        let mut s: Vec<u8> = format!("{:04}", x).bytes().map(|b| b - b'0').collect();
        if s.iter().any(|&i| !seen[i as usize]) {
            return false;
        }
        s.sort();
        s[0] == s[1] && s[2] == s[3] && s[1] != s[2]
    };

    let mut ans = 0;
    for i in 0..10000 {
        if ok(i) {
            ans += 1;
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
