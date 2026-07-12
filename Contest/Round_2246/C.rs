const MOD: i64 = 1_000_000_007;

fn pow(mut a: i64, mut b: i32) -> i64 {
    let mut ans = 1;
    while b > 0 {
        if b % 2 == 1 {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    ans
}

fn solve() {
    let n: usize = read();

    let mut m = 0;
    let mut p = 0;
    let mut d = 0;

    let mut adj = 0;
    let mut prev = 0;

    for _ in 0..n {
        let x: i32 = read();
        if x == -1 {
            m += 1;
        } else {
            p += 1;
            if x != prev {
                if prev > 0 && x == prev + 1 {
                    adj += 1;
                }
                d += 1;
                prev = x;
            }
        }
    }

    let mut ans = pow(2, p - d);
    if m > 0 {
        ans = ans * pow(2, m - 1) % MOD * (adj + 1) % MOD;
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
