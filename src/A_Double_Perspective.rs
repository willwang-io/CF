use std::{
    io::{self, Read},
    str::SplitWhitespace,
};

fn solve(io: &mut FastIO) -> () {}

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