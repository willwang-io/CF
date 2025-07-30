fn solve(io: &mut FastIO) -> () {
    let n: usize = io.read();
    if n % 4 != 0 {
        io.write("Alice");
    } else {
        io.write("Bob");
    }
}

fn main() {
    let mut io = FastIO::new();
    let t: usize = io.read();
    for _ in 0..t {
        solve(&mut io);
    }
}

use std::{
    io::{self, Read, Write},
    str::SplitWhitespace,
};

struct FastIO {
    iter: SplitWhitespace<'static>,
    out: io::BufWriter<io::StdoutLock<'static>>,
}

impl FastIO {
    fn new() -> Self {
        let mut buf = String::new();
        io::stdin().read_to_string(&mut buf).unwrap();
        let s: &'static str = Box::leak(buf.into_boxed_str());

        FastIO {
            iter: s.split_whitespace(),
            out: io::BufWriter::new(io::stdout().lock()),
        }
    }

    fn read<T: std::str::FromStr>(&mut self) -> T
    where
        T::Err: std::fmt::Debug,
    {
        self.iter.next().unwrap().parse().unwrap()
    }

    fn write<T: std::fmt::Display>(&mut self, val: T) {
        writeln!(self.out, "{}", val).unwrap();
    }
}