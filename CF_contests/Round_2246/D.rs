const LOG: usize = 17;
const MAX: usize = 1 << LOG;
const INF: i64 = i64::MAX / 4;

fn solve(b: &[Vec<i64>]) {
    let n: usize = read();
    let a: Vec<usize> = (0..n).map(|_| read()).collect();

    let sum: i64 = a.iter().map(|&x| x as i64).sum();
    let mut ans = INF;

    for c in 0..=LOG {
        let mut cur = -sum - (n as i64 - 1) * c as i64;
        for &x in &a {
            cur += b[c][x];
        }
        ans = ans.min(cur);
    }
    println!("{ans}");
}

fn main() {
    let mut b = vec![vec![INF; MAX + 1]; LOG + 1];

    for c in 0..=LOG {
        let mut mn = INF;
        for x in (1..=MAX).rev() {
            if x % (1 << c) == 0 {
                mn = mn.min(
                    x as i64 + x.count_ones() as i64 + (usize::BITS - 1 - x.leading_zeros()) as i64,
                );
            }
            b[c][x] = mn;
        }
    }

    let t: usize = read();
    for _ in 0..t {
        solve(&b);
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
