use std::{
    io::{self, Read},
    str::SplitWhitespace,
};

fn solve(io: &mut FastIO) -> () {
    let n: usize = io.read();
    let mut a: Vec<usize> = (0..n).map(|_| io.read()).collect();
    a.sort();
    if a[0] == a[n - 1] {
        println!("NO");
        return;
    }
    println!("YES");
    print!("{} ", a[0]);
    for i in (1..n).rev() {
        print!("{} ", a[i]);
    }
    println!();
}

fn main() {
    let mut io = FastIO::new();
    let t: usize = io.read();
    for _ in 0..t {
        solve(&mut io);
    }
}

struct FastIO {
    iter: SplitWhitespace<'static>,
}

impl FastIO {
    fn new() -> Self {
        let mut buf = String::new();
        io::stdin().read_to_string(&mut buf).unwrap();
        let s: &'static str = Box::leak(buf.into_boxed_str());

        FastIO {
            iter: s.split_whitespace(),
        }
    }

    fn read<T: std::str::FromStr>(&mut self) -> T
    where
        T::Err: std::fmt::Debug,
    {
        self.iter.next().unwrap().parse().unwrap()
    }
}